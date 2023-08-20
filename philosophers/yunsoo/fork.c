/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:01:09 by suhyun            #+#    #+#             */
/*   Updated: 2023/08/08 23:05:45 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

void	pickup_fork(t_phil *phil)
{
	pthread_mutex_lock(&phil->data->fork[phil->left_fork]);
	message_print(phil, "has taken a le fork");
	pthread_mutex_lock(&phil->data->fork[phil->right_fork]);
	message_print(phil, "has taken a ri fork");
}

void	pickdown_fork(t_phil *phil)
{
	pthread_mutex_unlock(&phil->data->fork[phil->right_fork]);
	pthread_mutex_unlock(&phil->data->fork[phil->left_fork]);
}
