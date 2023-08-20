/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:39:40 by yeckim            #+#    #+#             */
/*   Updated: 2023/02/20 15:33:29 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/stat.h>
# include <semaphore.h>

struct	s_d;

typedef struct s_p
{
	int			id;
	int			eat_cnt;
	struct s_d	*info;
}	t_philo;

typedef struct s_d
{
	long long		philos;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		time_to_die;
	long long		must_eat_cnt;
	long long		start_time;
	sem_t			*forks;
	sem_t			*finish;
	sem_t			*died;
	sem_t			*wait;
	t_philo			*philo;
}	t_data;

long long	ft_atoi(char *str);
int			err(char *msg);
int			start_philo(t_data *data, int ac);
long long	get_time(void);
int			argument_error_check(int ac, char **av);
void		unlink_close_col(t_data *data);
void		one_philo(t_data *data, t_philo *p);
void		print(t_data *data, int id, char *msg);
void		pass_time(long long wait_time, t_data *data, \
		int id, long long start);
int			finish(t_data *data, int ac, pid_t *pid);
#endif
