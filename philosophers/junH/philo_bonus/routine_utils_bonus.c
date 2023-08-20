/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:10:00 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/11 15:10:01 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time_diff_in_ms(struct timeval start, struct timeval end)
{
	long long	diff;

	diff = ((end.tv_sec - start.tv_sec) * 1000) + \
			((end.tv_usec - start.tv_usec) / 1000);
	return (diff);
}

void	print_state(t_philo philo, char *msg)
{
	long long		diff;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	diff = get_time_diff_in_ms(philo.data.init_time, curr);
	sem_wait(philo.data.print_sem);
	printf("%lld %d %s\n", diff, philo.idx, msg);
	sem_post(philo.data.print_sem);
}

void	wait_time(int duration)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	while (TRUE)
	{
		gettimeofday(&end, NULL);
		if (get_time_diff_in_ms(start, end) >= duration)
			break ;
		usleep(100);
	}
}
