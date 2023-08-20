/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kumamon <kumamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:13:48 by yeckim            #+#    #+#             */
/*   Updated: 2023/08/17 16:45:51 by kumamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	die(t_info *data, t_philo *p)
{
	pthread_mutex_lock(&data->died_check);
	if (!data->died)
	{
		data->died++;
		printf("%lld %lld %s\n", get_time() - data->start_time, p->id + 1, "died");
		pthread_mutex_lock(&data->died_check);
	}
	pthread_mutex_unlock(&data->died_check);
	return (1);
}

void	finish_check(t_info *data)
{
	// int	i;

	// i = -1;
	if (data->died)
		return ;
	printf("%s\n", "all philosopher ate");
}

void	*one_philo(t_info *data, t_philo *p)
{
	long long	now;

	now = get_time();
	print(data, p->id, "has taken a fork");
	pass_time(data->time_to_die, data, p, now);
	data->died++;
	return (0);
}

void	print(t_info *data, int id, char *str)
{
	pthread_mutex_lock(&data->print);
	if (!data->died)
	{
		printf("%lld %d %s\n", (get_time() - \
					data->start_time), id + 1, str);
	}
	pthread_mutex_unlock(&data->print);
}
