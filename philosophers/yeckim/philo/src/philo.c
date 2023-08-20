/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:47:20 by yeckim            #+#    #+#             */
/*   Updated: 2023/02/20 15:15:04 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	act_sleep(t_info *data, t_philo *p)
{
	if (p->eat_cnt == data->must_eat_cnt)
		return (0);
	print(data, p->id, "is sleeping");
	if (pass_time(data->time_to_sleep, data, p, get_time()) || data->died)
		return (1);
	print(data, p->id, "is thinking");
	return (0);
}

int	routine(t_info *data, t_philo *p, long long start)
{
	pthread_mutex_lock(&data->forks[p->left_fork]);
	print(data, p->id, "has taken a fork");
	pthread_mutex_lock(&data->forks[p->right_fork]);
	print(data, p->id, "has taken a fork");
	print(data, p->id, "is eating");
	if (pass_time(data->time_to_eat, data, p, start) || data->died)
	{
		pthread_mutex_unlock(&data->forks[p->right_fork]);
		pthread_mutex_unlock(&data->forks[p->left_fork]);
		return (1);
	}
	p->eat_cnt++;
	pthread_mutex_unlock(&data->forks[p->right_fork]);
	pthread_mutex_unlock(&data->forks[p->left_fork]);
	return (act_sleep(data, p));
}

void	*ft_thread(void *temp)
{
	t_philo		*p;
	t_info		*data;
	long long	start;

	p = temp;
	data = p->info;
	start = get_time();
	if (data->philos == 1)
		return (one_philo(data, p));
	if (p->id % 2)
		usleep(data->time_to_eat * 800);
	while (!data->died)
	{
		if (routine(data, p, start) || p->eat_cnt == data->must_eat_cnt)
			break ;
		start = get_time();
	}
	return (0);
}

int	start_philo(t_info *data)
{
	int	i;

	i = -1;
	while (++i < data->philos)
		if (pthread_create(&data->philo[i].thread, \
					NULL, ft_thread, &data->philo[i]))
			return (1);
	i = -1;
	while (++i < data->philos)
		pthread_join(data->philo[i].thread, NULL);
	finish_check(data);
	return (0);
}
