/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:26 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/04 10:28:27 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data, t_philo *philos, t_args args)
{
	int	i;

	i = 0;
	while (i < args.num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i].lock);
		i += 1;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->time_lock);
	pthread_mutex_destroy(&data->data_lock);
	pthread_mutex_destroy(&data->dead_flag_lock);
	free(philos);
}
