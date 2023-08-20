/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:36:31 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/17 04:13:58 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_print(char *msg)
{
	printf("%s", msg);
	return (FALSE);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)(((tv.tv_sec) * 1000) + ((tv.tv_usec) / 1000)));
}

void	philos_usleep(int milli_seconds)
{
	long long	start_time;
	long long	end_time;

	start_time = get_time();
	end_time = start_time + milli_seconds;
	while (get_time() <= end_time)
	{
		usleep(200);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	while ((9 <= *(str + i) && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	sign = 1;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	if (*(str + i) == '+' || *(str + i) == '-')
		return (0);
	res = 0;
	while (str[i] != '\0')
	{
		if ('0' > *(str + i) || *(str + i) > '9')
			return (-1);
		res = (res * 10) + (*(str + i) - '0');
		i++;
	}
	return (sign * res);
}

void	print_state(t_philo *philo, char *message)
{
	long long		diff;
	long long		current_time;
	t_philo_args	*arg;

	arg = philo->arg;
	current_time = get_time();
	diff = current_time - arg->time_of_start;
	pthread_mutex_lock(&arg->print_mutex_lock);
	pthread_mutex_lock(&arg->dead_mutex_lock);
	if (arg->dead == DEAD && philo->print_dead == FALSE)
	{
		printf("%lld %d %s\n", diff, philo->id_of_philo + 1, "died");
		philo->print_dead = TRUE;
	}
	else if (arg->dead != DEAD && philo->print_dead == FALSE)
	{
		printf("%lld %d %s\n", diff, philo->id_of_philo + 1, message);
	}
	pthread_mutex_unlock(&arg->print_mutex_lock);
	pthread_mutex_unlock(&arg->dead_mutex_lock);
}
