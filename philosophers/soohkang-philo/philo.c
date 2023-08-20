/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:00:55 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/17 04:11:14 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_args	args;

	if (argc < 5 || argc > 6)
		return (error_print(INVALID_ARGS));
	init_args(argc, argv, &args);
	if (is_valid_args(&args) == FALSE)
		return (error_print(ERROR_ARGS));
	init_mutex_fork(&args);
	init_philos_data(&args);
	init_philos_threads(&args);
	remove_philos(&args);
	mutex_delete(&args);
	free_all_args(&args);
	return (TRUE);
}
