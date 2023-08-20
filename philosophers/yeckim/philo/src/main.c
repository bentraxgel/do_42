/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kumamon <kumamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:05:41 by yeckim            #+#    #+#             */
/*   Updated: 2023/08/17 16:45:40 by kumamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_argument(t_info *data, int ac)
{
	if (data->philos <= 0 || data->time_to_die < 0 || \
			data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (1);
	if (ac == 6)
		if (data->must_eat_cnt <= 0)
			return (1);
	return (0);
}

int	philo_init(t_info *data)
{
	int	i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->philos);
	if (data->philo == NULL)
		return (1);
	i = -1;
	while (++i < data->philos)
	{
		data->philo[i].id = i;
		data->philo[i].eat_cnt = 0;
		data->philo[i].info = data;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->philos;
	}
	return (0);
}

int	mutex_init(t_info *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos);
	if (data->forks == NULL)
		return (1);
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	i = -1;
	while (++i < data->philos)
	{
		if (pthread_mutex_init(&data->philo[i].check_time, NULL))
			return (1);
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
	}
	return (0);
}

int	init(t_info *data, int ac, char **av)
{
	// int	i;

	data->start_time = get_time();
	data->philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat_cnt = -1;
	if (ac == 6)
		data->must_eat_cnt = ft_atoi(av[5]);
	if (check_argument(data, ac) || philo_init(data) || mutex_init(data))
		return (1);
	data->died = 0;
	data->finished_eat = 0;
	// i = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_info	data;

	if (ac < 5 || ac > 6)
		return (err("argument error!"));
	if (argument_error_check(ac, av))
		return (err("argument error!"));
	memset(&data, 0, sizeof(data));
	if (init(&data, ac, av))
		return (err("init error!"));
	if (start_philo(&data))
		return (err("start philo error!"));
	free(data.forks);
	free(data.philo);
	return (0);
}
