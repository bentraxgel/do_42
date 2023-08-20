/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:19 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/14 08:18:26 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define MS					1000

# define CHILD_PROCESS		0

# define SUCCESS			0

# define ERROR				-1
# define FALSE				0
# define TRUE				1

# define INVALID_ARGUMENT	"❌Error: Invalid arguments"
# define FORK_ERROR			"❌Error: fork error occured."

# define EATING				"is eating"
# define SLEEP				"is sleeping"
# define THINKING			"is thinking"
# define DIED				"is died"
# define PICK_UP_FORK		"has taken a fork"

# define FORK_SEMAPHORE			"/fork_semaphore"
# define TIME_SEMAPHORE			"/time_semaphore"
# define PRINT_SEMAPHORE		"/print_semaphore"
# define FINISH_SEMAPHORE		"/finish_semaphore"
# define EATEN_SEMAPHORE		"/eaten_semaphore"
# define DEAD_PRINT_SEMAPHORE	"/dead_print_semaphore"

typedef struct s_args
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_times_of_eat;
}	t_args;

typedef struct s_data
{
	t_args			args;
	sem_t			*forks;
	sem_t			*print_sem;
	sem_t			*finish_sem;
	sem_t			*time_sem;
	sem_t			*eaten_sem;
	sem_t			*dead_print_sem;
	pid_t			*child_process;
	pthread_t		finish_thread;
	pthread_t		eaten_thread;
	struct timeval	init_time;
}	t_data;

typedef struct s_philo
{
	int				idx;
	t_args			args;
	t_data			data;
	int				times_of_eat;
	pthread_t		monitor;
	struct timeval	last_time_of_eat;
}	t_philo;

// clear_data_bonus.c
void		clear_data(t_data *data);

// create_philos_bonus.c
void		create_philos(t_data *data, t_args args);
void		*monitor_all_philo_eaten(void *arg);

// ft_atoi_bonus.c
int			ft_atoi(const char *str);

// init_data_bonus.c
void		init_data(t_data *data, t_args args);
sem_t		*create_semaphore(char *name, int value);

// main_utils_bonus.c
int			is_valid_arguments(t_args args);
int			throw_error(char *msg);
void		save_args(t_args *args, int argc, char **argv);
void		wait_child_process(t_data data);

// monitor_bonus.c
void		*monitor_philo(void *arg);
void		*monitor_finish(void *arg);
void		*monitor_all_philo_eaten(void *arg);

// routine_bonus.c
void		start_routine(t_philo philo);

// routine_utils_bonus.c
long long	get_time_diff_in_ms(struct timeval start, struct timeval end);
void		print_state(t_philo philo, char *msg);
void		wait_time(int duration);

#endif