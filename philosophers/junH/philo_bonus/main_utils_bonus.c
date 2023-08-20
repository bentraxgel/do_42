/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:54:05 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/12 08:25:04 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_child_process(t_data data)
{
	int	i;

	i = 0;
	while (i < data.args.num_of_philo)
	{
		if (waitpid(data.child_process[i], NULL, 0) == ERROR)
			exit(EXIT_FAILURE);
		else
			i += 1;
	}
}

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
