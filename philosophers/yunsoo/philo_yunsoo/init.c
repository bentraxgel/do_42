/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:42:54 by suhyun            #+#    #+#             */
/*   Updated: 2023/08/08 22:58:20 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->total_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->ate_phil = 0;
	data->finish = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	data->fork = (pthread_mutex_t *)malloc \
				(sizeof(pthread_mutex_t) * data->total_philo);
	if (data->fork == NULL)
		return (NULL);
	if (pthread_mutex_init(&data->data_safe, NULL))
		return (NULL);
	return (data);
}

t_phil	*init_phil(t_data *data)
{
	t_phil	*ret;
	int		i;

	ret = (t_phil *)malloc(sizeof(t_phil) * data->total_philo);
	if (!ret)
		return (NULL);
	data->start_time = get_time();
	i = -1;
	while (++i < data->total_philo)
	{
		ret[i].phil_id = i;
		ret[i].left_fork = i;
		ret[i].right_fork = (i + 1) % data->total_philo;
		ret[i].eat_count = data->must_eat;
		ret[i].full = 0;
		ret[i].last_eat_time = get_time();
		ret[i].data = data;
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (NULL);
	}
	return (ret);
}
