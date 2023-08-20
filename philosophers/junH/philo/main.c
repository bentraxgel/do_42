/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:30 by joonhan           #+#    #+#             */
/*   Updated: 2023/08/10 14:06:40 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args		args;
	t_data		data;
	t_philo		*philos;
	pthread_t	monitoring;

	if (argc < 5 || argc > 6)
		return (throw_error(INVALID_ARGUMENT));
	save_args(&args, argc, argv);
	if (is_valid_arguments(args) == FALSE)
		return (throw_error(INVALID_ARGUMENT));
	init_data(&data, args);
	philos = create_philos(&data, args);
	pthread_create(&monitoring, NULL, start_monitoring, philos);
	wait_thread(philos, args);
	pthread_join(monitoring, NULL);
	free_all(&data, philos, args);
	return (EXIT_SUCCESS);
}
