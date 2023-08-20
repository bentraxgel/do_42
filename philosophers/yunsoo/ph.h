/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:59:54 by suhyun            #+#    #+#             */
/*   Updated: 2023/08/08 23:27:42 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_H
# define PH_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

# define ERROR 1

typedef struct s_data
{
	int				total_philo; //전체 필로
	int				time_to_die; //죽는 시간
	int				time_to_eat; //먹는 시간
	int				time_to_sleep; //자는 시간
	int				must_eat; // 먹어야하는 횟수 (필요 시)

	long long		start_time; // 만들어진 시간.

	int				ate_phil; // 다먹은 철학자 수

	int				finish;//////

	pthread_mutex_t	*fork; //포크 (공유 자원)
	// ptheread message
	pthread_mutex_t	data_safe;
}	t_data;

typedef struct s_phil
{
	pthread_t	thread;
	int			phil_id; //필로 인덱스 
	int			left_fork; // 포크 인덱스
	int			right_fork;
	int			eat_count; //먹은 획수

	int			full; //다 먹엇다

	long long	last_eat_time; // 마지막 먹은 시간.
	t_data		*data; //공유 데이터 참조
}	t_phil;

6int			ft_atoi(const char *str);
int			err_msg(char *msg);
int			check_arg(int ac, char **av);

void		wait_ex(int num);
long long	get_time(void);
void		message_print(t_phil *phil, char *msg);

t_data		*init_data(int ac, char **av);
t_phil		*init_phil(t_data *data);
void		thread_clear(t_data *data, t_phil *phil);
int			create_phil(t_data *data, t_phil *phil);

void		pickup_fork(t_phil *phil);
void		pickdown_fork(t_phil *phil);

int			take_meal(t_phil *phil);
int			try_eating(t_phil *phil);
int			check_finish(t_phil *phil);
void		sleep_thinking(t_phil *phil);

void		check_condition(t_data *data, t_phil *phil, int i);

#endif