/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:32:52 by seok              #+#    #+#             */
/*   Updated: 2023/05/22 05:28:45 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_three_only(t_stack *stack, t_info *info, size_t top)
{
	printf("three_only]\n");
	if (stack->a[top] > stack->a[top - 1] && stack->a[top] > stack->a[top - 2]\
		&& stack->a[top - 1] < stack->a[top - 2])
		command(RA, stack, info);
	else if (stack->a[top] > stack->a[top - 1] && stack->a[top] > stack->a[top - 2]\
		&& stack->a[top - 1] > stack->a[top - 2])
	{
		command(RA, stack, info);
		command(SA, stack, info);
	}
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
	{
		command(RRA, stack, info);
		command(SA, stack, info);
	}
	else if (stack->a[top] > stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
			command(SA, stack, info);
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] > stack->a[top - 2])
			command(RRA, stack, info);
}

void	a_three_another(t_stack *stack, t_info *info, size_t top)
{
	if (stack->a[top] > stack->a[top - 1] && stack->a[top] > stack->a[top - 2]\
		&& stack->a[top - 1] < stack->a[top - 2])
		a_first_case(stack, info);
	else if (stack->a[top] > stack->a[top - 1] && stack->a[top] > stack->a[top - 2]\
		&& stack->a[top - 1] > stack->a[top - 2])
	{
		a_first_case(stack, info);
		a_second_case(stack, info);
	}
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
		a_third_case(stack, info);
	else if (stack->a[top] > stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
		a_fourth_case(stack, info);
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] > stack->a[top - 2])
		a_fifth_case(stack, info);
}

void	b_three_only(t_stack *stack, t_info *info, size_t top)
{
	if (stack->b[top] < stack->b[top - 1] && stack->b[top] < stack->b[top - 2]\
		&& stack->b[top - 1] < stack->b[top - 2])
	{
		command(SB, stack, info);
		command(RRB, stack, info);
	}
	else if (stack->b[top] < stack->b[top - 1] && stack->b[top] < stack->b[top - 2]\
		&& stack->b[top - 1] < stack->b[top - 2])
		command(RB, stack, info);
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
	{
		command(RRB, stack, info);
		command(SB, stack, info);
	}
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] < stack->b[top - 2])
		command(RRB, stack, info);
	else if (stack->b[top] < stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
		command(SB, stack, info);
}

void	b_three_another(t_stack *stack, t_info *info, size_t top)
{
	if (stack->b[top] < stack->b[top - 1] && stack->b[top] < stack->b[top - 2]\
		&& stack->b[top - 1] < stack->b[top - 2])
		b_first_case(stack, info);
	else if (stack->b[top] < stack->b[top - 1] && stack->b[top] < stack->b[top - 2]\
		&& stack->b[top - 1] < stack->b[top - 2])
		b_second_case(stack, info);
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
		b_third_case(stack, info);
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] < stack->b[top - 2])
		b_fourth_case(stack, info);
	else if (stack->b[top] < stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
		b_fifth_case(stack, info);
}
