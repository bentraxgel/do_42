/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:09:59 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/14 08:19:40 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	thinking(t_philo *philo)
{
	sem_wait(philo->data.dead_print_sem);
	print_state(*philo, THINKING);
	sem_post(philo->data.dead_print_sem);
}

static void	sleeping(t_philo *philo)
{
	sem_wait(philo->data.dead_print_sem);
	print_state(*philo, SLEEP);
	sem_post(philo->data.dead_print_sem);
	wait_time(philo->args.time_to_sleep);
}

static void	pick_up_fork(t_philo *philo)
{
	sem_wait(philo->data.forks);
	sem_wait(philo->data.dead_print_sem);
	print_state(*philo, PICK_UP_FORK);
	sem_post(philo->data.dead_print_sem);
}

static void	eating(t_philo *philo)
{
	pick_up_fork(philo);
	pick_up_fork(philo);
	sem_wait(philo->data.time_sem);
	gettimeofday(&philo->last_time_of_eat, NULL);
	sem_post(philo->data.time_sem);
	sem_wait(philo->data.dead_print_sem);
	print_state(*philo, EATING);
	sem_post(philo->data.dead_print_sem);
	wait_time(philo->args.time_to_eat);
	philo->times_of_eat += 1;
	if (philo->times_of_eat == philo->args.min_times_of_eat)
	{
		sem_post(philo->data.eaten_sem);
	}
	sem_post(philo->data.forks);
	sem_post(philo->data.forks);
}

void	start_routine(t_philo philo)
{
	pthread_create(&philo.monitor, NULL, monitor_philo, &philo);
	pthread_detach(philo.monitor);
	if (philo.idx % 2 == 0)
		usleep(MS);
	while (TRUE)
	{
		eating(&philo);
		sleeping(&philo);
		thinking(&philo);
	}
	exit(EXIT_SUCCESS);
}
