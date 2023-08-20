/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:43:20 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/17 03:14:14 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_delete(t_philo_args *args)
{
	int	num_of_philos;

	num_of_philos = args->num_of_philo;
	while (num_of_philos--)
	{
		pthread_mutex_destroy(&args->forks[num_of_philos].mutex);
		pthread_mutex_destroy(&args->philos[num_of_philos].time_mutex_lock);
		pthread_mutex_destroy(&args->philos[num_of_philos].stop_mutex_lock);
		pthread_mutex_destroy(&args->philos[num_of_philos].meal_mutex_lock);
	}
	pthread_mutex_destroy(&args->print_mutex_lock);
	pthread_mutex_destroy(&args->dead_mutex_lock);
}

void	free_all_args(t_philo_args *args)
{
	free(args->forks);
	free(args->philos);
	free(args->philos_threads);
}

void	remove_philos(t_philo_args *args)
{
	int	num_of_philos;

	num_of_philos = args->num_of_philo;
	while (--num_of_philos >= 0)
	{
		if (pthread_join(args->philos_threads[num_of_philos], NULL) != 0)
			error_print("join error");
	}
}
