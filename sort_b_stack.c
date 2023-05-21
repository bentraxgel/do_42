/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 03:22:00 by seok              #+#    #+#             */
/*   Updated: 2023/05/21 05:23:24 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_three_only(t_stack *stack, t_info *info, int top)
{
	if (stack->b[top] < stack->b[top - 1] && stack->b[top] < stack->b[top - 2])
	{
		if (stack->b[top - 1] < stack->b[top - 2])
		{
			s_command(stack, STACK_B);
			rr_command(stack, STACK_B, stack->b_len);
		}
		else
			r_command(stack, info, STACK_B, stack->b_len);
	}
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
	{
		rr_command(stack, STACK_B, stack->b_len);
		s_command(stack, STACK_B);
	}
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] < stack->b[top - 2])
		rr_command(stack, STACK_B, stack->b_len);
	else if (stack->b[top] < stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
		s_command(stack, STACK_B);
}
/*
void	b_four_sort(t_stack *stack, t_info *info)
{
	int	i;

	i = -1;
	info->pa = 0;
	info->rb = 0;
	b_stack_indexing(stack, stack->b_len - 4, 4);
	while (++i < 4)
	{
		if (stack->b[stack->b_len - 1] == 0 || stack->b[stack->b_len - 1] == 1)
			r_command(stack, info, STACK_B, stack->b_len - 1);
		else
			p_command(stack, info, STACK_A);
	}
	while (info->rb-- != 0)
		rr_command(stack, STACK_B, stack->b_len - 1);
	two_sort(stack, STACK_A, stack->a_len -1);
	two_sort(stack, STACK_B, stack->b_len -1);
	while (info->pa-- != 0)
		p_command(stack, info, STACK_B);
}
*/