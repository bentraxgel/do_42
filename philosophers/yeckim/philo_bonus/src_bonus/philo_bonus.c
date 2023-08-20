/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:53:41 by yeckim            #+#    #+#             */
/*   Updated: 2023/02/20 15:34:48 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/philo_bonus.h"

void	print(t_data *data, int id, char *msg)
{
	sem_wait(data->died);
	printf("%lld %d %s\n", get_time() - data->start_time, id + 1, msg);
	sem_post(data->died);
}

void	pass_time(long long wait_time, t_data *data, int id, long long start)
{
	long long	cur;
	long long	i;

	cur = get_time();
	while (get_time() - cur < wait_time)
	{
		usleep(100);
		if (get_time() - start >= data->time_to_die)
			break ;
	}
	i = -1;
	sem_wait(data->died);
	usleep(60);
	if (get_time() - start >= data->time_to_die)
	{
		printf("%lld %d %s\n", get_time() - data->start_time, id + 1, "died");
		while (++i < data->philos)
			sem_post(data->finish);
		sem_wait(data->died);
	}
	sem_post(data->died);
}

void	routine(t_data *data, t_philo *p, long long time)
{
	sem_wait(data->forks);
	print(data, p->id, "has taken a fork");
	sem_wait(data->forks);
	print(data, p->id, "has taken a fork");
	print(data, p->id, "is eating");
	pass_time(data->time_to_eat, data, p->id, time);
	p->eat_cnt++;
	sem_post(data->forks);
	sem_post(data->forks);
	if (p->eat_cnt == data->must_eat_cnt)
	{
		sem_post(data->finish);
		sem_open("ate", O_CREAT, 0644, 1);
		sem_wait(data->wait);
	}
	print(data, p->id, "is sleeping");
	pass_time(data->time_to_sleep, data, p->id, get_time());
	print(data, p->id, "is thinking");
}

void	child(t_philo *p)
{
	t_data		*data;
	long long	cur;

	data = p->info;
	cur = get_time();
	if (data->philos == 1)
		return (one_philo(data, p));
	if (p->id % 2)
		usleep(data->time_to_eat * 800);
	while (1)
	{
		routine(data, p, cur);
		cur = get_time();
	}
}

int	start_philo(t_data *data, int ac)
{
	long long	i;
	pid_t		*pid;

	i = -1;
	pid = (pid_t *)malloc(sizeof(pid_t) * data->philos);
	if (pid == NULL)
		return (1);
	while (++i < data->philos)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			child(&data->philo[i]);
	}
	return (finish(data, ac, pid));
}
