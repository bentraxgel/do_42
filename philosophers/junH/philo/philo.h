/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:19 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/08 10:14:28 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define MS		1000

# define ERROR	-1
# define FALSE	0
# define TRUE	1

# define INVALID_ARGUMENT	"❌Error: Invalid arguments"

# define EATING			"is eating"
# define SLEEP			"is sleeping"
# define THINKING		"is thinking"
# define DIED			"is died"
# define PICK_UP_FORK	"has taken a fork"

enum e_philo_status
{
	DIE,
	EATEN
};

enum e_fork_status
{
	LOCK,
	UNLOCK
};

enum e_hand
{
	LEFT,
	RIGHT
};

typedef struct s_args
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_times_of_eat;
}	t_args;

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				status;
}	t_fork;

typedef struct s_data
{
	pthread_mutex_t	time_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	data_lock;
	pthread_mutex_t	dead_flag_lock;
	t_fork			*forks;
	struct timeval	init_time;
	int				is_dead_msg_printed;
	int				is_other_philo_dead;
	int				is_all_philos_eaten;
	int				num_of_eaten_philo;
}	t_data;

typedef struct s_philo
{
	int				idx;
	t_args			args;
	t_data			*data;
	pthread_t		thread;
	t_fork			*forks[2];
	int				times_of_eat;
	struct timeval	last_time_of_eat;
}	t_philo;

// create_philos.c
t_philo		*create_philos(t_data *data, t_args args);

// ft_atoi.c
int			ft_atoi(const char *str);

// init_data.c
void		init_data(t_data *data, t_args args);

// routine.c
void		*start_routine(void *arg);
int			is_other_philo_dead(t_data *data);

// routine_utils.c
void		wait_time(int duration);
int			is_other_philo_dead(t_data *data);
void		print_state(t_philo *philo, char *msg);
long long	get_time_diff_in_ms(struct timeval start, struct timeval end);

// fork.c
void		pick_up_fork(t_philo *philo, enum e_hand hand);
void		put_down_fork(t_philo *philo, enum e_hand hand);

// main_utils.c
int			is_valid_arguments(t_args args);
int			throw_error(char *msg);
void		wait_thread(t_philo *philos, t_args args);
void		save_args(t_args *args, int argc, char **argv);

// monitoring.c
void		*start_monitoring(void *arg);
int			is_all_philo_eaten(t_philo *philo);

// free_all.c
void		free_all(t_data *data, t_philo *philos, t_args args);

#endif