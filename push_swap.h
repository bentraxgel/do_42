/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:37 by seok              #+#    #+#             */
/*   Updated: 2023/05/05 05:20:00 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef enum e_set
{
	STACK_A = 0,
	STACK_B,
}t_set;

typedef struct s_info
{
	t_list		*command;
	int			*a;
	int			*b;
	int			*sort;
	long long	a_len;
	long long	b_len;
	long long	total_len;
} t_info;

void	my_error();

#endif