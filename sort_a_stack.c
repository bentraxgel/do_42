/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:24:55 by seok              #+#    #+#             */
/*   Updated: 2023/05/21 06:44:32 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_three_only(t_stack *stack, t_info *info, int top)
{
	if (stack->a[top] > stack->a[top - 1] && stack->a[top] > stack->a[top - 2])
	{
		r_command(stack, info, STACK_A, stack->a_len);
		if (stack->a[top - 1] > stack->a[top - 2])
			s_command(stack, STACK_A);
	}
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
	{
		rr_command(stack, STACK_A, stack->a_len);
		s_command(stack, STACK_A);
	}
	else if (stack->a[top] > stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
		s_command(stack, STACK_A);
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] > stack->a[top - 2])
		rr_command(stack, STACK_A, stack->a_len);
}

void	a_four_only(t_stack *stack, t_info *info)
{
	int	i;

	i = -1;
	info->pb = 0;
	info->ra = 0;
	a_stack_indexing(stack, stack->a_len - 4, 4);
	while (++i < 4)
	{
		if (stack->a[stack->a_len - 1] == 0 || stack->a[stack->a_len - 1] == 1)
			p_command(stack, info, STACK_B);
		else
			r_command(stack, info, STACK_A, stack->a_len - 1);
	}
	while (info->ra-- > 0)
		rr_command(stack, STACK_A, stack->a_len - 1);
	two_sort(stack, STACK_A);
	two_sort(stack, STACK_B);
	while (info->pb-- > 0)
		p_command(stack, info, STACK_A);
}

void	a_five_only(t_stack *stack, t_info *info)
{
	int	i;

	i = -1;
	info->pb = 0;
	info->ra = 0;
	a_stack_indexing(stack, stack->a_len - 5, 5);
	while (++i < 5)
	{
		if (stack->a[stack->a_len - 1] == 0 || stack->a[stack->a_len - 1] == 1)
			p_command(stack, info, STACK_B);
		else
			r_command(stack, info, STACK_A, stack->a_len - 1);
	}
	while (info->ra-- > 0)
		rr_command(stack, STACK_A, stack->a_len - 1);
	a_three_only(stack, info, stack->a_len -1);
	two_sort(stack, STACK_B);
	while (info->pb-- > 0)
		p_command(stack, info, STACK_A);
}