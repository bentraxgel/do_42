/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:29 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/14 08:18:17 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*create_semaphore(char *name, int value)
{
	sem_t	*semaphore;

	semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (semaphore == SEM_FAILED)
		sem_unlink(name);
	return (sem_open(name, O_CREAT, 0644, value));
}

void	init_data(t_data *data, t_args args)
{
	data->args = args;
	data->forks = create_semaphore(FORK_SEMAPHORE, args.num_of_philo);
	data->time_sem = create_semaphore(TIME_SEMAPHORE, 1);
	data->print_sem = create_semaphore(PRINT_SEMAPHORE, 1);
	data->finish_sem = create_semaphore(FINISH_SEMAPHORE, 0);
	data->eaten_sem = create_semaphore(EATEN_SEMAPHORE, 0);
	data->dead_print_sem = create_semaphore(DEAD_PRINT_SEMAPHORE, 1);
	data->child_process = malloc(sizeof(pid_t) * args.num_of_philo);
	gettimeofday(&data->init_time, NULL);
}
