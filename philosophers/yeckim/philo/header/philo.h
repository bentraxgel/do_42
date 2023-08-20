/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:00:25 by yeckim            #+#    #+#             */
/*   Updated: 2023/02/20 15:24:32 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_data;

typedef struct s_p
{
	long long		id;
	long long		eat_cnt;
	long long		left_fork;
	long long		right_fork;
	struct s_data	*info;
	pthread_t		thread;
	pthread_mutex_t	check_time;
}	t_philo;

typedef struct s_data
{
	long long		philos;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		time_to_die;
	long long		must_eat_cnt;
	int				died;
	int				finished_eat;
	pthread_mutex_t	died_check;
	pthread_mutex_t	finish;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_t		thread;
	long long		start_time;
	t_philo			*philo;
}	t_info;

int			argument_error_check(int ac, char **av);
long long	ft_atoi(char *str);
int			start_philo(t_info *data);
int			err(char *str);
int			pass_time(long long wait_time, t_info *data, \
		t_philo *p, long long start);
int			check_died(t_info *data);
int			die(t_info *data, t_philo *p);
void		*one_philo(t_info *data, t_philo *p);
void		finish_check(t_info *data);
void		print(t_info *data, int id, char *str);
long long	get_time(void);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
#endif
