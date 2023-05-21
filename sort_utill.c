/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:14:53 by seok              #+#    #+#             */
/*   Updated: 2023/05/21 07:49:51 by seok             ###   ########.fr       */
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

void	two_sort(t_stack *stack, t_set flag)
{
	if (flag == STACK_A)
	{
		if (stack->a[stack->a_len] < stack->a[stack->a_len - 1])
			return ;
		else if (stack->a[stack->a_len] > stack->a[stack->a_len - 1])
			s_command(stack, STACK_A);
	}
	else if (flag == STACK_B)
	{
		if (stack->b[stack->b_len] > stack->b[stack->b_len - 1])
			return ;
		else if (stack->b[stack->b_len] < stack->b[stack->b_len - 1])
			s_command(stack, STACK_B);
	}
}
// /*
void	hard_sort(t_stack *stack, t_info *info, int num, t_set flag)
{
	if (num == 1)
		return ;
	else if (num == 2)
		two_sort(stack, flag);
	else
	{
		if (flag == STACK_A)
			a_hard_sort(stack, info, num);
		else
			b_hard_sort(stack, info, num);
	}
}

void	a_hard_sort(t_stack *stack, t_info *info, int num)
{
	if (stack->a_len == num)
	{
		if (num == 3)
			a_three_only(stack, info, stack->a_len);
		// else if (num == 4)
		// 	a_four_only(stack, info);
		// // else
		// 	a_five_only(stack, info);
	}
	// else
	// {
	// 	if (num == 3)
	// 		a_three_another(stack, info, stack->a_len);
	// 	else if (num == 4)
	// 		a_four_another(stack, info);
	// 	else
	// 		a_five_another(stack, info);
	// }
}

void	b_hard_sort(t_stack *stack, t_info *info, int num)
{
	if (stack->b_len == num)
	{
		if (num == 3)
			b_three_only(stack, info, stack->b_len);
		// else if (num == 4)
			// b_four_only(stack, info);
		// else
		// 	b_five_only(stack, info);
	}
	// else
	// {
	// 	if (num == 3)
	// 		b_three_another(stack, info, stack->b_len);
	// 	else if (num == 4)
	// 		b_four_another(stack, info);
	// 	else
	// 		b_five_another(stack, info);
	// }
}
// */