/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:25 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/04 10:38:28 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_thread_create(t_philo *philo)
{
	return (pthread_create(&philo->thread, NULL, start_routine, philo));
}

t_philo	*create_philos(t_data *data, t_args args)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * args.num_of_philo);
	if (philos == NULL)
		return (NULL);
	while (i < args.num_of_philo)
	{
		philos[i].idx = i + 1;
		philos[i].args = args;
		philos[i].data = data;
		philos[i].times_of_eat = 0;
		philos[i].forks[LEFT] = &data->forks[i];
		philos[i].forks[RIGHT] = &data->forks[(i + 1) % args.num_of_philo];
		gettimeofday(&philos[i].last_time_of_eat, NULL);
		if (ft_thread_create(&philos[i]) != 0)
			return (NULL);
		i += 1;
	}
	return (philos);
}
