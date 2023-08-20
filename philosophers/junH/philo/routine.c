/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:32 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/08 10:25:35 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philo *philo)
{
	pick_up_fork(philo, LEFT);
	if (philo->args.num_of_philo == 1)
	{
		usleep(philo->args.time_to_die * MS);
		return ;
	}
	pick_up_fork(philo, RIGHT);
	print_state(philo, EATING);
	philo->times_of_eat += 1;
	if (philo->args.min_times_of_eat > 0 && \
		philo->times_of_eat == philo->args.min_times_of_eat)
	{
		pthread_mutex_lock(&philo->data->data_lock);
		philo->data->num_of_eaten_philo += 1;
		pthread_mutex_unlock(&philo->data->data_lock);
	}
	pthread_mutex_lock(&philo->data->time_lock);
	gettimeofday(&philo->last_time_of_eat, NULL);
	pthread_mutex_unlock(&philo->data->time_lock);
	wait_time(philo->args.time_to_eat);
	put_down_fork(philo, RIGHT);
	put_down_fork(philo, LEFT);
}

void	start_sleeping(t_philo *philo)
{
	print_state(philo, SLEEP);
	wait_time(philo->args.time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	print_state(philo, THINKING);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->idx % 2 == 0)
		usleep(500);
	while (TRUE)
	{
		if (is_other_philo_dead(philo->data) == TRUE)
			break ;
		if (is_all_philo_eaten(philo) == TRUE)
			break ;
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (arg);
}
