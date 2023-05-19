/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 03:22:00 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 04:14:15 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	b_three_sort(t_stack *stack, int idx)
{
	if (stack->b[idx] < stack->b[idx + 1] && stack->b[idx] < stack->b[idx + 2])
	{
		if (stack->b[idx + 1] < stack->b[idx + 2])
		{
			s_command(stack, STACK_B);
			rr_command(stack, STACK_B, stack->b_len);
		}
		else
			r_command(stack, STACK_B, stack->b_len);

	}
	else if (stack->b[idx] > stack->b[idx + 1] && stack->b[idx] > stack->b[ idx + 2])
	{
		rr_command(stack, STACK_B, stack->b_len);
		s_command(stack, STACK_B);
	}
	else if (stack->b[idx] > stack->b[idx + 1] && stack->b[idx] < stack->b[idx + 2])
		rr_command(stack, STACK_B, stack->b_len);
	else if (stack->b[idx] < stack->b[idx + 1] && stack->b[idx] > stack->b[idx + 2])
		s_command(stack, STACK_B);
}