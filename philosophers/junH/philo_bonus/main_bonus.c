/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:30 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/12 08:26:34 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_args		args;
	t_data		data;

	if (argc < 5 || argc > 6)
		return (throw_error(INVALID_ARGUMENT));
	save_args(&args, argc, argv);
	if (is_valid_arguments(args) == FALSE)
		return (throw_error(INVALID_ARGUMENT));
	init_data(&data, args);
	if (data.args.min_times_of_eat != 0)
	{
		pthread_create(&data.eaten_thread, NULL, \
						monitor_all_philo_eaten, &data);
	}
	pthread_create(&data.finish_thread, NULL, monitor_finish, &data);
	create_philos(&data, args);
	wait_child_process(data);
	clear_data(&data);
	return (EXIT_SUCCESS);
}
