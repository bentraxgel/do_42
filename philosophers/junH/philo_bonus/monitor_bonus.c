/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:09:58 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/14 08:22:59 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_philo(void *arg)
{
	struct timeval	curr;
	long long		diff;
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (TRUE)
	{
		gettimeofday(&curr, NULL);
		sem_wait(philo->data.time_sem);
		diff = get_time_diff_in_ms(philo->last_time_of_eat, curr);
		sem_post(philo->data.time_sem);
		sem_wait(philo->data.dead_print_sem);
		if (diff >= philo->args.time_to_die)
		{
			print_state(*philo, DIED);
			sem_post(philo->data.finish_sem);
			return (arg);
		}
		sem_post(philo->data.dead_print_sem);
	}
	return (arg);
}

void	*monitor_finish(void *arg)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)arg;
	if (sem_wait(data->finish_sem) == 0)
	{
		while (i < data->args.num_of_philo)
		{
			sem_post(data->eaten_sem);
			i += 1;
		}
		i = 0;
		while (i < data->args.num_of_philo)
		{
			kill(data->child_process[i], SIGKILL);
			i += 1;
		}
	}
	return (arg);
}

void	*monitor_all_philo_eaten(void *arg)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)arg;
	while (i < data->args.num_of_philo)
	{
		sem_wait(data->eaten_sem);
		i += 1;
	}
	sem_post(data->finish_sem);
	return (NULL);
}
