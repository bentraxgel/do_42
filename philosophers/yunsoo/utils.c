/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 02:09:06 by suhyun            #+#    #+#             */
/*   Updated: 2023/08/02 00:52:04 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ret;

	gettimeofday(&time, NULL);
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	wait_ex(int num)
{
	long long	time;

	time = get_time();
	while (get_time() - time < num)
		usleep(100);
}

void	message_print(t_phil *phil, char *msg)
{
	long long	time;

	time = get_time();
	pthread_mutex_lock(&phil->data->data_safe);
	if (!phil->data->finish)
	{
		printf("%lld %d %s\n", \
				time - phil->data->start_time, phil->phil_id + 1, msg);
	}
	pthread_mutex_unlock(&phil->data->data_safe);
}

int	check_finish(t_phil *phil)
{
	pthread_mutex_lock(&phil->data->data_safe);
	if (phil->data->finish)
	{
		pthread_mutex_unlock(&phil->data->data_safe);
		return (1);
	}
	pthread_mutex_unlock(&phil->data->data_safe);
	return (0);
}

void	thread_clear(t_data *data, t_phil *phil)
{
	int	i;

	i = 0;
	if (data->total_philo == 1)
	{
		pthread_detach(phil->thread);
		return ;
	}
	while (i < data->total_philo)
	{
		pthread_join(phil[i].thread, NULL);
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->data_safe);
	free(phil);
	free(data->fork);
	free(data);
}
