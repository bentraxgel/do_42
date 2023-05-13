/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:37 by seok              #+#    #+#             */
/*   Updated: 2023/05/13 21:49:19 by seok             ###   ########.fr       */
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
	int			*total;
	size_t	a_len;
	size_t	b_len;
	size_t	total_len;
} t_info;

//utill.c
void	my_error();
int	*ft_indexing(int *arr, size_t len);

//command.c
void	r_command(t_info *stack, int flag, size_t len);
void	rr_command(t_info *stack, int flag, size_t len);
void	p_command(t_info *stack, int flag);
void	s_command(t_info *stack, int flag);

//print.c
t_list	*r_print(t_list *command);
t_list	*rr_print(t_list *command);
t_list	*s_print(t_list *command);
void	print_command(t_list *command);

#endif
