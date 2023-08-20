/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seodong-gyun <seodong-gyun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:49:07 by dongkseo          #+#    #+#             */
/*   Updated: 2023/06/26 23:44:51 by seodong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*get_info(int ac, char **av)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	table->num_of_philo = ft_atoi(av[1]);
	table->time_of_die = ft_atoi(av[2]);
	table->time_of_eat = ft_atoi(av[3]);
	table->time_of_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->limit_of_eat = ft_atoi(av[5]);
	else
		table->limit_of_eat = -1;
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->num_of_philo);
	if (!table->fork)
		return (NULL);
	return (table);
}

t_philo	*init_philo(t_table *table)
{
	int		i;
	t_philo	*ph;

	table->start_time = get_time();
	ph = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philo);
	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		ph[i].id = i;
		ph[i].table = table;
		ph[i].left = i;
		ph[i].time_die = table->time_of_die;
		ph[i].right = (i + 1) % table->num_of_philo;
		ph[i].must_eat = table->limit_of_eat;
		ph[i].last_eat = get_time();
		i++;
	}
	pthread_mutex_init(&table->safe, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	return (ph);
}
