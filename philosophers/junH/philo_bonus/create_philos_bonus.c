/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:09:50 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/11 15:09:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philos(t_data *data, t_args args)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < args.num_of_philo)
	{
		philo.idx = i + 1;
		philo.args = args;
		philo.times_of_eat = 0;
		philo.data = *data;
		gettimeofday(&philo.last_time_of_eat, NULL);
		data->child_process[i] = fork();
		if (data->child_process[i] == CHILD_PROCESS)
		{
			return (start_routine(philo));
		}
		i += 1;
	}
}
