/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:09:48 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/14 08:21:38 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clear_data(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->time_sem);
	sem_close(data->finish_sem);
	sem_close(data->print_sem);
	sem_close(data->eaten_sem);
	sem_close(data->dead_print_sem);
	sem_unlink(FORK_SEMAPHORE);
	sem_unlink(TIME_SEMAPHORE);
	sem_unlink(FINISH_SEMAPHORE);
	sem_unlink(PRINT_SEMAPHORE);
	sem_unlink(EATEN_SEMAPHORE);
	sem_unlink(DEAD_PRINT_SEMAPHORE);
	free(data->child_process);
	pthread_join(data->finish_thread, NULL);
	pthread_join(data->eaten_thread, NULL);
}
