/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkseo <dongkseo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:25:36 by dongkseo          #+#    #+#             */
/*   Updated: 2023/05/04 20:09:27 by dongkseo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_table
{
	int				num_of_philo;
	int				time_of_die;
	int				time_of_eat;
	int				time_of_sleep;
	int				limit_of_eat;
	int				count;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	safe;
	pthread_t		monitoring;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				num_eaten;
	int				left;
	int				right;
	int				time_die;
	int				must_eat;
	long long		last_eat;
	long long		start_time;
	struct s_table	*table;
	pthread_t		thread;
}	t_philo;

typedef struct s_check
{
	char	**split_tmp;
	char	*itoa_tmp;
	int		data;
}	t_check;

// # --- LIBFT --- #
// atoi
int			ft_atoi(const char *str);
// split
int			word_count(char const *s, char c);
char		**ft_split(char const *s, char c);
char		**ft_putstring(char const *s, char c, char **arr);
char		**ft_clearall(int j, char **arr);
int			string_len(char const *s, char c);
// itoa
int			nb_len(long long nb);
void		write_int(long long nb, char *arr, int *lev);
char		*ft_itoa(int n);

// # --- PHILO_ACTION --- # 
void		philo_print(t_philo *ph, char *msg, int flag);
void		philo_thinking(t_philo *philo);
void		philo_sleeping(t_philo *philo);
int			philo_eating(t_philo *philo);
void		philo_pickup_fork(t_philo *philo);

// # --- INIT_DATA --- #
t_table		*get_info(int ac, char **av);
t_philo		*init_philo(t_table *table);

// # --- CHECK_DATA --- #
int			ft_check(int ac, char **av);

// # --- UTILS --- #
void		free_all_arg(t_table *table, t_philo *philo, int num);
void		clear_thread(t_philo *philo, int num);
void		wait_(int time);
long long	get_time(void);

// # --- MONITOR --- #
void		monitor(t_table *table, t_philo *philo, int num);

#endif