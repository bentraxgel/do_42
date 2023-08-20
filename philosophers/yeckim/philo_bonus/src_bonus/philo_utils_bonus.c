/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:37:14 by yeckim            #+#    #+#             */
/*   Updated: 2023/02/20 13:29:36 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/philo_bonus.h"

void	one_philo(t_data *data, t_philo *p)
{
	long long	cur;

	cur = get_time();
	print(data, p->id, "has taken a fork");
	while (get_time() - cur < data->time_to_die)
		usleep(100);
	print(data, p->id, "died");
	sem_post(data->finish);
}

int	finish(t_data *data, int ac, pid_t *pid)
{
	int	i;

	i = -1;
	if (ac == 5)
		sem_wait(data->finish);
	else
		while (++i < data->philos)
			sem_wait(data->finish);
	i = -1;
	while (++i < data->philos)
		kill(pid[i], SIGKILL);
	free(pid);
	if (sem_open("ate", O_CREAT | O_EXCL, 0644, 1) == SEM_FAILED)
		printf("all philosopher ate");
	return (0);
}

void	unlink_close_col(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("finish");
	sem_unlink("died");
	sem_unlink("wait");
	sem_close(data->forks);
	sem_close(data->finish);
	sem_close(data->died);
	sem_close(data->wait);
}
