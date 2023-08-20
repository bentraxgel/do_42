/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:36:09 by yeckim            #+#    #+#             */
/*   Updated: 2023/02/20 13:29:17 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/philo_bonus.h"

int	philo_init(t_data *data)
{
	int	i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->philos);
	if (data->philo == NULL)
		return (1);
	i = 0;
	while (i < data->philos)
	{
		data->philo[i].id = i;
		data->philo[i].eat_cnt = 0;
		data->philo[i].info = data;
		i++;
	}
	return (0);
}

int	check_argument(t_data *data, int ac)
{
	if (data->philos <= 0 || data->time_to_die < 0 || data->time_to_eat < 0 \
			|| data->time_to_sleep < 0)
		return (1);
	if (ac == 6)
		if (data->must_eat_cnt <= 0)
			return (1);
	return (0);
}

int	semaphore_init(t_data *data)
{	
	sem_unlink("forks");
	sem_unlink("finish");
	sem_unlink("died");
	sem_unlink("wait");
	sem_unlink("ate");
	data->forks = sem_open("forks", O_CREAT, 0644, data->philos);
	data->finish = sem_open("finish", O_CREAT, 0644, 1);
	data->died = sem_open("died", O_CREAT, 0644, 1);
	data->wait = sem_open("wait", O_CREAT, 0644, 1);
	return (0);
}

int	init(t_data *data, int ac, char **av)
{
	data->philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat_cnt = -1;
	if (ac == 6)
		data->must_eat_cnt = ft_atoi(av[5]);
	if (check_argument(data, ac) || philo_init(data) || semaphore_init(data))
		return (1);
	data->start_time = get_time();
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (err("argument error!\n"));
	if (argument_error_check(ac, av))
		return (err("argument error!\n"));
	if (init(&data, ac, av))
		return (err("argument init error!\n"));
	sem_wait(data.finish);
	sem_wait(data.wait);
	if (start_philo(&data, ac))
		return (err("start philo error!\n"));
	unlink_close_col(&data);
	free(data.philo);
	return (0);
}
