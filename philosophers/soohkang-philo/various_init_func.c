/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_init_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kumamon <kumamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:23:43 by soohkang          #+#    #+#             */
/*   Updated: 2023/08/19 16:45:51 by kumamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int argc, char **argv, t_philo_args *args)
{
	args->num_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->num_of_finish_philo = 0;
	args->dead = NOT_DEAD;
	args->time_of_start = get_time();
	if (argc == 6)
		args->num_philo_must_eat = ft_atoi(argv[5]);
	else
		args->num_philo_must_eat = 0;
}

int	is_valid_args(t_philo_args *args)
{
	if (args->num_of_philo <= 0 || args->time_to_die <= 0 \
	|| args->time_to_eat <= 0 || args->time_to_sleep <= 0 \
	|| args->num_philo_must_eat < 0)
		return (FALSE);
	return (TRUE);
}

void	init_mutex_fork(t_philo_args *args)
{
	int		num_of_philos;
	t_fork	*forks;

	num_of_philos = args->num_of_philo;
	forks = malloc(sizeof(t_fork) * (num_of_philos));
	if (!forks)
		return ;
	while (num_of_philos--)
	{
		pthread_mutex_init(&forks[num_of_philos].mutex, NULL);
		forks[num_of_philos].status = UNLOCK;
	}
	pthread_mutex_init(&args->print_mutex_lock, NULL);
	args->forks = forks;
}

void	init_philos_data(t_philo_args *args)
{
	int		idx;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * (args->num_of_philo));
	if (!philos)
		return ;
	idx = -1;
	while (++idx < args->num_of_philo)
	{
		philos[idx].id_of_philo = idx;
		philos[idx].num_of_philo = args->num_of_philo;
		philos[idx].total_num_of_meals = 0;
		philos[idx].how_many_should_philo_eat = args->num_philo_must_eat;
		philos[idx].time_to_eat = args->time_to_eat;
		philos[idx].time_to_sleep = args->time_to_sleep;
		philos[idx].time_to_die = args->time_to_die;
		philos[idx].time_of_last_eat = get_time();
		philos[idx].print_dead = FALSE;
		philos[idx].stopped = 0;
		philos[idx].fork[LEFT] = &args->forks[philos[idx].id_of_philo];
		philos[idx].fork[RIGHT] = \
			&args->forks[(philos[idx].id_of_philo + 1) % (args->num_of_philo)];
		philos[idx].arg = args;
	}
	args->philos = philos;
}

void	init_philos_threads(t_philo_args *args)
{
	pthread_t	*philos_threads;
	int			num_of_philos;

	num_of_philos = args->num_of_philo;
	philos_threads = malloc(sizeof(pthread_t) * args->num_of_philo);
	if (!philos_threads)
		return ;
	pthread_mutex_init(&args->dead_mutex_lock, NULL);
	while (num_of_philos--)
	{
		pthread_mutex_init(&args->philos[num_of_philos].time_mutex_lock, NULL);
		pthread_mutex_init(&args->philos[num_of_philos].stop_mutex_lock, NULL);
		pthread_mutex_init(&args->philos[num_of_philos].meal_mutex_lock, NULL);
		pthread_create(&philos_threads[num_of_philos], NULL, \
				what_philos_do, &args->philos[num_of_philos]);
		usleep(1000);
	}
	philos_monitor(args->philos);
	args->philos_threads = philos_threads;
}
