/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 01:53:11 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/17 04:12:29 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_philo_dead(t_philo *philo)
{
	int	idx;

	idx = 0;
	pthread_mutex_lock(&philo->arg->dead_mutex_lock);
	philo->arg->dead = DEAD;
	pthread_mutex_unlock(&philo->arg->dead_mutex_lock);
	print_state(philo, "died");
	while (idx < philo[idx].num_of_philo)
	{
		pthread_mutex_lock(&philo[idx].stop_mutex_lock);
		philo[idx].stopped = STOPPED;
		pthread_mutex_unlock(&philo[idx].stop_mutex_lock);
		idx++;
	}
}

t_return	is_all_philo_eaten(t_philo *philo)
{
	int				idx;
	t_return		result;
	t_philo_args	*arg;

	idx = 0;
	result = FALSE;
	arg = philo->arg;
	pthread_mutex_lock(&philo->meal_mutex_lock);
	pthread_mutex_lock(&philo->stop_mutex_lock);
	if (philo->total_num_of_meals == philo->how_many_should_philo_eat && \
			philo->stopped == STOPPED)
		arg->num_of_finish_philo += 1;
	pthread_mutex_unlock(&philo->stop_mutex_lock);
	if (arg->num_of_finish_philo == arg->num_of_philo)
	{
		while (idx < arg->num_of_philo)
		{
			pthread_mutex_lock(&arg->philos[idx].stop_mutex_lock);
			arg->philos[idx].stopped = STOPPED;
			pthread_mutex_unlock(&arg->philos[idx++].stop_mutex_lock);
		}
		result = TRUE;
	}
	pthread_mutex_unlock(&philo->meal_mutex_lock);
	return (result);
}

void	philos_monitor(t_philo *philo)
{
	int			idx;
	long long	diff;

	idx = 0;
	while (idx < philo->num_of_philo)
	{
		pthread_mutex_lock(&philo[idx].time_mutex_lock);
		diff = get_time() - philo[idx].time_of_last_eat;
		pthread_mutex_unlock(&philo[idx].time_mutex_lock);
		if (diff > philo->arg->time_to_die)
		{
			is_philo_dead(philo);
			return ;
		}
		if (philo->how_many_should_philo_eat > 0 \
					&& is_all_philo_eaten(&philo[idx]))
			return ;
		if (is_philo_stop(&philo[idx]))
			return ;
		idx = (idx + 1) % philo->num_of_philo;
	}
}
