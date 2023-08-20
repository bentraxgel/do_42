/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:31 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/04 10:37:40 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_philo_dead(t_philo *philo)
{
	int				result;
	struct timeval	curr;

	result = FALSE;
	gettimeofday(&curr, NULL);
	pthread_mutex_lock(&philo->data->time_lock);
	if (get_time_diff_in_ms(philo->last_time_of_eat, curr) \
							>= philo->args.time_to_die)
	{
		result = TRUE;
	}
	pthread_mutex_unlock(&philo->data->time_lock);
	return (result);
}

int	is_all_philo_eaten(t_philo *philo)
{
	int				result;

	result = FALSE;
	pthread_mutex_lock(&philo->data->data_lock);
	if (philo->data->num_of_eaten_philo == philo->args.num_of_philo)
		result = TRUE;
	pthread_mutex_unlock(&philo->data->data_lock);
	return (result);
}

static void	change_common_data(t_philo *philo, enum e_philo_status status)
{
	if (status == DIE)
	{
		pthread_mutex_lock(&philo->data->dead_flag_lock);
		philo->data->is_other_philo_dead = TRUE;
		pthread_mutex_unlock(&philo->data->dead_flag_lock);
	}
	else if (status == EATEN)
	{
		pthread_mutex_lock(&philo->data->data_lock);
		philo->data->is_all_philos_eaten = TRUE;
		pthread_mutex_unlock(&philo->data->data_lock);
	}
}

void	*start_monitoring(void *arg)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)arg;
	while (TRUE)
	{
		if (is_philo_dead(&philos[i]) == TRUE)
		{
			change_common_data(&philos[i], DIE);
			print_state(&philos[i], DIED);
			break ;
		}
		if (is_all_philo_eaten(&philos[i]) == TRUE)
		{
			change_common_data(&philos[i], EATEN);
			break ;
		}
		i = (i + 1) % philos[i].args.num_of_philo;
	}
	return (arg);
}
