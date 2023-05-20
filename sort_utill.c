/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:14:53 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 18:03:01 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_pivot(int start, int len, t_info *info)
{
	info->p1 = ((len - start) / 3) + start;
	info->p2 = ((len - start) / 3 * 2) + start;
	info->pa = 0;
	info->pb = 0;
	info->ra = 0;
	info->rb = 0;
}

void	two_sort(t_stack *stack, int flag, int idx)
{
	if (flag == STACK_A)
	{
		if (stack->a[idx] < stack->a[idx - 1])
			return ;
		else if (stack->a[idx] > stack->a[idx - 1])
			s_command(stack, STACK_A);
	}
	else if (flag == STACK_B)
	{
		if (stack->b[idx] > stack->b[idx - 1])
			return ;
		else if (stack->b[idx] < stack->b[idx - 1])
			s_command(stack, STACK_B);
	}
}

// void	hard_sort(int len, int flag, t_stack *stack)
// {
// 	if (len == 3)
// 	{
// 		if (flag == STACK_A)
// 			a_three_sort(stack, len - 1);
// 		else
// 			b_three_sort(stack, len - 1);
// 	}
// 	else if (len == 4)
// 		four_sort(stack, flag, len - 1); /TODO just len
// 	else
// 		five_sort(stack, flag, len - 1);

// }