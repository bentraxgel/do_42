/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:44:07 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/12 17:32:06 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	is_other_philo_dead(t_data *data)
{
	int	result;

	result = FALSE;
	pthread_mutex_lock(&data->dead_flag_lock);
	if (data->is_other_philo_dead == TRUE)
		result = TRUE;
	pthread_mutex_unlock(&data->dead_flag_lock);
	return (result);
}

void	print_state(t_philo *philo, char *msg)
{
	long long		timestamp;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	timestamp = get_time_diff_in_ms(philo->data->init_time, curr);
	pthread_mutex_lock(&philo->data->print_lock);
	if (is_other_philo_dead(philo->data) == FALSE)
		printf("%lld %d %s\n", timestamp, philo->idx, msg);
	else if (philo->data->is_dead_msg_printed == FALSE)
	{
		philo->data->is_dead_msg_printed = TRUE;
		printf("%lld %d %s\n", timestamp, philo->idx, msg);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

long long	get_time_diff_in_ms(struct timeval start, struct timeval end)
{
	long long	diff;

	diff = ((end.tv_sec - start.tv_sec) * 1000) + \
			((end.tv_usec - start.tv_usec) / 1000);
	return (diff);
}
