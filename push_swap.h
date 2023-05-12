/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:37 by seok              #+#    #+#             */
/*   Updated: 2023/05/12 15:37:48 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

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
	size_t	a_len;
	size_t	b_len;
	size_t	total_len;
} t_info;

//utill.c
void	my_error();

//command.c
void	r_command(t_info *stack, int flag, size_t len);
void	rr_command(t_info *stack, int flag, size_t len);
void	p_command(t_info *stack, int flag);
void	s_command(t_info *stack, int flag);

#endif
