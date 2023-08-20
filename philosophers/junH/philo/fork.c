/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:47:58 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/04 10:51:16 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_fork(t_philo *philo, enum e_hand hand)
{
	while (TRUE)
	{
		pthread_mutex_lock(&philo->forks[hand]->lock);
		if (philo->forks[hand]->status == UNLOCK)
		{
			philo->forks[hand]->status = LOCK;
			print_state(philo, PICK_UP_FORK);
			pthread_mutex_unlock(&philo->forks[hand]->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->forks[hand]->lock);
		usleep(200);
	}
}

void	put_down_fork(t_philo *philo, enum e_hand hand)
{
	pthread_mutex_lock(&philo->forks[hand]->lock);
	philo->forks[hand]->status = UNLOCK;
	pthread_mutex_unlock(&philo->forks[hand]->lock);
}
