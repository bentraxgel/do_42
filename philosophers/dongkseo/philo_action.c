/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seodong-gyun <seodong-gyun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:44:56 by dongkseo          #+#    #+#             */
/*   Updated: 2023/07/18 20:35:55 by seodong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->left]);
	philo_print(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->table->fork[philo->right]);
	philo_print(philo, "has taken a fork", 0);
}

int	philo_eating(t_philo *philo)
{
	philo_print(philo, "is eating", 0);
	pthread_mutex_lock(&philo->table->safe);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->table->safe);
	wait_(philo->table->time_of_eat);
	pthread_mutex_unlock(&philo->table->fork[philo->right]);
	pthread_mutex_unlock(&philo->table->fork[philo->left]);
	pthread_mutex_lock(&philo->table->safe);
	philo->must_eat--;
	if (philo->must_eat == 0)
	{
		philo->table->count++;
		pthread_mutex_unlock(&philo->table->safe);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->safe);
	return (0);
}

void	philo_sleeping(t_philo *philo)
{
	philo_print(philo, "is sleeping", 0);
	wait_(philo->table->time_of_sleep);
}

void	philo_thinking(t_philo *philo)
{
	philo_print(philo, "is thinking", 0);
}

void	philo_print(t_philo *ph, char *msg, int flag)
{
	long long	now;

	now = get_time();
	if (ph->table->time_of_eat == 0 && ph->table->time_of_sleep == 0)
		usleep(200);
	pthread_mutex_lock(&ph->table->print_mutex);
	printf("%lld %d %s\n", (now - ph->table->start_time), ph->id + 1, msg);
	if (flag == 0)
		pthread_mutex_unlock(&ph->table->print_mutex);
}
