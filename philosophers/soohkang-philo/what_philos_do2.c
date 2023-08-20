/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_philos_do2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:06:39 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/17 04:13:30 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, t_fork *fork)
{
	while (TRUE)
	{
		pthread_mutex_lock(&philo->stop_mutex_lock);
		if (philo->stopped != STOPPED)
		{
			pthread_mutex_lock(&fork->mutex);
			if (fork->status == UNLOCK)
			{
				fork->status = LOCK;
				print_state(philo, TAKE_FORK);
				pthread_mutex_unlock(&fork->mutex);
				pthread_mutex_unlock(&philo->stop_mutex_lock);
				return ;
			}
			pthread_mutex_unlock(&fork->mutex);
			pthread_mutex_unlock(&philo->stop_mutex_lock);
		}
		else
		{
			pthread_mutex_unlock(&philo->stop_mutex_lock);
			return ;
		}
		usleep(300);
	}
}

void	put_down_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->status = UNLOCK;
	pthread_mutex_unlock(&fork->mutex);
}

void	taking_forks(t_philo *philo)
{
	take_fork(philo, philo->fork[RIGHT]);
	take_fork(philo, philo->fork[LEFT]);
}

void	eating(t_philo *philo)
{
	print_state(philo, "is eating");
	if (philo->how_many_should_philo_eat > 0)
	{
		pthread_mutex_lock(&philo->meal_mutex_lock);
		philo->total_num_of_meals++;
		pthread_mutex_lock(&philo->stop_mutex_lock);
		if (philo->total_num_of_meals == philo->how_many_should_philo_eat)
			philo->stopped = STOPPED;
		pthread_mutex_unlock(&philo->stop_mutex_lock);
		pthread_mutex_unlock(&philo->meal_mutex_lock);
	}
	pthread_mutex_lock(&philo->time_mutex_lock);
	philo->time_of_last_eat = get_time();
	pthread_mutex_unlock(&philo->time_mutex_lock);
	philos_usleep(philo->time_to_eat);
	put_down_fork(philo->fork[LEFT]);
	put_down_fork(philo->fork[RIGHT]);
}

void	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	philos_usleep(philo->time_to_sleep);
}
