/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:29 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/04 10:28:30 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_fork	*create_forks(t_args args)
{
	int		i;
	t_fork	*forks;

	i = 0;
	forks = malloc(sizeof(t_fork) * args.num_of_philo);
	while (i < args.num_of_philo)
	{
		forks[i].status = UNLOCK;
		pthread_mutex_init(&forks[i].lock, NULL);
		i += 1;
	}
	return (forks);
}

void	init_data(t_data *data, t_args args)
{
	data->forks = create_forks(args);
	data->num_of_eaten_philo = 0;
	data->is_dead_msg_printed = FALSE;
	data->is_all_philos_eaten = FALSE;
	pthread_mutex_init(&data->time_lock, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->data_lock, NULL);
	pthread_mutex_init(&data->dead_flag_lock, NULL);
	gettimeofday(&data->init_time, NULL);
}
