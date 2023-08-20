/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 02:53:10 by suhyun            #+#    #+#             */
/*   Updated: 2023/08/08 23:21:00 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

int	take_meal(t_phil *phil)
{
	message_print(phil, "is eating");
	wait_ex(phil->data->time_to_eat);
	pickdown_fork(phil);
	pthread_mutex_lock(&phil->data->data_safe);
	phil->last_eat_time = get_time();
	phil->eat_count--;
	if (phil->eat_count == 0)
	{
		phil->data->ate_phil++;
		phil->full = 1;
		pthread_mutex_unlock(&phil->data->data_safe);
		return (1);
	}
	pthread_mutex_unlock(&phil->data->data_safe);
	return (0);
}

void	phil_routine(void *data)
{
	t_phil	*phil;

	phil = (t_phil *)data;
	if (phil->data->total_philo == 1)
	{
		pickup_fork(phil);
		return ;
	}
	if (phil->phil_id % 2 == 0)
		wait_ex(phil->data->time_to_eat / 2);
	while (1)
	{
		pickup_fork(phil);
		if (take_meal(phil))
			break ;
		if (check_finish(phil))
			break ;
		message_print(phil, "is sleeping");
		wait_ex(phil->data->time_to_sleep);
		message_print(phil, "is thinking");
	}
}

void	check_condition(t_data *data, t_phil *phil, int i)
{
	long long	time;

	time = get_time();
	if (time - phil[i].last_eat_time > data->time_to_die && !(phil[i].full))
	{
		if (data->finish == 0)
			printf("%lld %d died\n", time - data->start_time, phil->phil_id + 1);
		data->finish = 1;
		return ;
	}
	if (data->ate_phil == data->total_philo)
	{
		if (data->finish == 0)
			printf("yummy\n");
		data->finish = 1;
		return ;
	}
}

void	check_death(t_data *data, t_phil *phil)
{
	int			i;

	while (1)
	{
		i = 0;
		while (i < data->total_philo)
		{
			pthread_mutex_lock(&phil->data->data_safe);
			check_condition(data, phil, i);
			if (data->finish == 1)
			{
				pthread_mutex_unlock(&phil->data->data_safe);
				thread_clear(data, phil);
				return ;
			}
			pthread_mutex_unlock(&phil->data->data_safe);
			i++;
		}
		usleep(100);
	}
}

int	create_phil(t_data *data, t_phil *phil)
{
	int	i;

	i = -1;
	while (++i < data->total_philo)
		if (pthread_create(&phil[i].thread, NULL, \
				(void *)phil_routine, &phil[i]))
			return (ERROR);
	check_death(data, phil);
	return (0);
}
