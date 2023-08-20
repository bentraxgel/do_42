/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 02:14:34 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/17 04:14:09 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define INVALID_ARGS "Need 5 or 6 arguments!\n"
# define ERROR_ARGS "Error arguments\n"
# define MALLOC_ERROR "Failed to allocate memory for philos!\n"

# define TAKE_FORK "has taken a fork"

# define ONE_PERSON 1
# define STOPPED 1
# define ERROR -1
# define SUCCESS 1
# define NOT_DEAD 0
# define DEAD 1

typedef enum e_fork_status
{
	LOCK,
	UNLOCK
}	t_fork_status;

typedef enum e_philo_hand
{
	LEFT,
	RIGHT
}	t_philo_hand;

typedef enum e_return
{
	FALSE,
	TRUE
}	t_return;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				status;
}	t_fork;

typedef struct s_philo
{
	int					id_of_philo;
	int					total_num_of_meals;
	int					how_many_should_philo_eat;
	long long			time_of_last_eat;
	int					num_of_philo;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					stopped;
	int					print_dead;
	pthread_mutex_t		time_mutex_lock;
	pthread_mutex_t		stop_mutex_lock;
	pthread_mutex_t		meal_mutex_lock;
	struct s_philo_args	*arg;
	t_fork				*fork[2];
}	t_philo;

typedef struct s_philo_args
{
	int				num_of_philo;
	int				id_of_philo;
	long long		time_of_start;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				dead;
	int				num_philo_must_eat;
	int				num_of_finish_philo;
	t_fork			*forks;
	pthread_t		*philos_threads;
	pthread_mutex_t	print_mutex_lock;
	pthread_mutex_t	dead_mutex_lock;
	t_philo			*philos;
}	t_philo_args;

// initialize
void		init_args(int argc, char **argv, t_philo_args *args);
int			is_valid_args(t_philo_args *args);
void		init_mutex_fork(t_philo_args *args);
void		init_philos_data(t_philo_args *args);
void		init_philos_threads(t_philo_args *args);

// philos do
t_return	is_other_dead(t_philo_args *args);
t_return	is_philo_stop(t_philo *philo);
void		*what_philos_do(void *args);

// philos do 2
void		taking_forks(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);

// monitor
void		is_philo_dead(t_philo *philo);
t_return	is_all_philo_eaten(t_philo *philo);
void		philos_monitor(t_philo *philo);

// utils
int			error_print(char *msg);
int			ft_atoi(const char *str);
void		print_state(t_philo *philo, char *message);

// utils2
long long	get_time(void);
void		free_all_args(t_philo_args *args);
void		mutex_delete(t_philo_args *args);
void		remove_philos(t_philo_args *args);
void		philos_usleep(int milli_seconds);

#endif
