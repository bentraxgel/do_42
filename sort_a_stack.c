/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:24:55 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 19:29:54 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_three_sort(t_stack *stack, int idx)
{
	if (stack->a[idx] > stack->a[idx + 1] && stack->a[idx] > stack->a[idx + 2])
	{
		r_command(stack, STACK_A, stack->a_len);
		if (stack->a[idx + 1] > stack->a[idx + 2])
			s_command(stack, STACK_A);
	}
	else if (stack->a[idx] < stack->a[idx + 1] && stack->a[idx] < stack->a[idx + 2])
	{
		rr_command(stack, STACK_A, stack->a_len);
		s_command(stack, STACK_A);
	}
	else if (stack->a[idx] > stack->a[idx + 1] && stack->a[idx] < stack->a[idx + 2])
		s_command(stack, STACK_A);
	else if (stack->a[idx] < stack->a[idx + 1] && stack->a[idx] > stack->a[idx + 2])
		rr_command(stack, STACK_A, stack->a_len);
}

void	a_four_sort(t_stack *stack, int idx)
{
	int	i;
	int pb;
	int	ra;

	i = -1;
	pb = 0;
	ra = 0;
	a_stack_indexing(stack, stack->a_len - 4, 4);

	while (++i < 4)
	{
		if (stack->a[stack->a_len - 1] == 0 || stack->a[stack->a_len - 1] == 1)
		{
			p_command(stack, STACK_A);
			pb++;
		}
		else
		{
			r_command(stack, STACK_A, stack->a_len - 1);
			ra++;
		}
	}
	while (ra--)
		rr_command(stack, STACK_A, stack->a_len - 1);
	two_sort(stack, STACK_A, stack->a_len -1);
	two_sort(stack, STACK_B, stack->b_len -1);
	while (pb--)
		p_command(stack, STACK_B);
}


void	slkfja_four_sort(t_stack *stack, int idx)
{
	int	i;
	int pb;

	i = -1;
	pb = 0;
	a_stack_indexing(stack, idx - 4, 4);
	while (i < 4)
	{
		if (stack->a[idx + i] <= 1)
		{
			p_command(stack, STACK_A);
			pb++;
		}
		else
			r_command(stack, STACK_A, stack->a_len);
	}
	two_sort(stack, STACK_A, stack->a_len);
	two_sort(stack, STACK_B, stack->b_len);
	while (pb--)
		p_command(stack, STACK_B);
}