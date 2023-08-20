/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seodong-gyun <seodong-gyun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:50:56 by dongkseo          #+#    #+#             */
/*   Updated: 2023/06/26 23:44:41 by seodong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	if (time.tv_usec > 2)
		ms = (time.tv_sec * 1000) + (time.tv_usec * 1e-3);
	else
		ms = (time.tv_sec * 1000);
	return (ms);
}

void	wait_(int time)
{
	long long	t1;

	t1 = get_time();
	while (get_time() - t1 < time)
		usleep(500);
}

void	clear_thread(t_philo *philo, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		pthread_detach(philo[i].thread);
}

void	free_all_arg(t_table *table, t_philo *philo, int num)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->safe);
	while (++i < num)
		pthread_mutex_destroy(&table->fork[i]);
	free(table->fork);
	free(table);
	free(philo);
}
