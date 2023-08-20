/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:17 by yeckim            #+#    #+#             */
/*   Updated: 2023/02/21 16:49:58 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	return (1);
}

long long	ft_atoi(char *str)
{
	long long	num;

	num = 0;
	while (*str && *str == ' ')
		str++;
	if (*str == '-' || *str == '\0')
			return (-1);
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int	argument_error_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] && av[i][j] == ' ')
			j++;
		while (av[i][j])
		{
			if (('0' > av[i][j] || '9' < av[i][j]) && av[i][j] != ' ')
				return (1);
			j++;
		}
	}
	return (0);
}

long long	get_time(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return (temp.tv_sec * 1000 + temp.tv_usec / 1000);
}

int	pass_time(long long wait_time, t_info *data, t_philo *p, long long start)
{
	long long	cur;

	cur = get_time();
	while (!data->died && get_time() - cur < wait_time)
	{
		usleep(100);
		if (get_time() - start >= data->time_to_die)
			break ;
	}
	if (get_time() - start >= data->time_to_die)
		return (die(data, p));
	return (0);
}
