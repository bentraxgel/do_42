/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:54:05 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/08 10:23:53 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_arguments(t_args args)
{
	if (args.num_of_philo <= 0 || args.time_to_die <= 0 || \
		args.time_to_eat <= 0 || args.time_to_sleep <= 0 || \
		args.min_times_of_eat < 0)
		return (FALSE);
	return (TRUE);
}

int	throw_error(char *msg)
{
	printf("%s\n", msg);
	return (EXIT_FAILURE);
}

void	wait_thread(t_philo *philos, t_args args)
{
	int	i;

	i = 0;
	while (i < args.num_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL) == 0)
			i += 1;
	}
}

void	save_args(t_args *args, int argc, char **argv)
{
	args->num_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args->min_times_of_eat = ft_atoi(argv[5]);
		if (args->min_times_of_eat == 0)
			args->min_times_of_eat = ERROR;
	}
	else
		args->min_times_of_eat = 0;
}
