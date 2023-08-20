/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_philos_do.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kumamon <kumamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:06:46 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/19 16:45:34 by kumamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_return	is_other_dead(t_philo_args *args)
{
	t_return	result;

	result = FALSE;
	pthread_mutex_lock(&args->dead_mutex_lock);
	if (args->dead == DEAD)
		result = TRUE;
	pthread_mutex_unlock(&args->dead_mutex_lock);
	return (result);
}

t_return	is_philo_stop(t_philo *philo)
{
	t_return	result;

	result = FALSE;
	pthread_mutex_lock(&philo->stop_mutex_lock);
	if (philo->stopped == STOPPED)
	{
		result = TRUE;
	}
	pthread_mutex_unlock(&philo->stop_mutex_lock);
	return (result);
}

void	*what_philos_do(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (philo->id_of_philo % 2 == 0)
	// 	usleep(500);
	pthread_mutex_lock(&philo->time_mutex_lock);
	philo->time_of_last_eat = get_time();
	pthread_mutex_unlock(&philo->time_mutex_lock);
	while (!is_other_dead(philo->arg))
	{
		if (philo->num_of_philo == 1)
		{
			philos_usleep(philo->time_to_die);
			return (NULL);
		}
		if (is_philo_stop(philo))
			return (NULL);
		taking_forks(philo);
		eating(philo);
		sleeping(philo);
		print_state(philo, "is thinking");
		if (is_other_dead(philo->arg) || is_philo_stop(philo))
			return (NULL);
	}
	return (NULL);
}
