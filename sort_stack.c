// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort_stack.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/22 00:35:00 by seok              #+#    #+#             */
// /*   Updated: 2023/05/23 21:40:06 by seok             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void	a_stack_sort(t_stack *stack, size_t num)
// {
// 	t_info	info;

// 	if (stack->b_len == 0 && a_sort_check(stack->a, stack->a_len) == TRUE)
// 		return ;
// 	if (num <= 6)
// 	{
// 		hard_sort(stack, &info, num, STACK_A);
// 		return ;
// 	}
// 	save_pivot(stack, &info, STACK_A, num);
// 	while (--num >= 0)
// 	{
// 		if (info.p2 <= stack->a[num])
// 			command(RA, stack, &info);
// 		else
// 		{
// 			command(PA, stack, &info);
// 			if (info.p1 <= stack->a[num])
// 				command(RB, stack, &info);
// 		}
// 	}
// 	sort_rr(stack, &info);
// 	a_stack_sort(stack, info.ra);
// 	b_stack_sort(stack, info.rb, &info);
// 	b_stack_sort(stack, info.pb - info.rb, &info);
// }

// void	b_stack_sort(t_stack *stack, size_t num, t_info *info)
// {
// 	if (num <= 6)
// 	{
// 		hard_sort(stack, info, num, STACK_B);
// 		while (num--)
// 			p_command(stack, info, STACK_B);
// 		return ;
// 	}
// 	save_pivot(stack, info, STACK_B, num);
// 	while (--num >= 0)
// 	{
// 		if (stack->a[num] < info->p1)
// 			command(RB, stack, info);
// 		else
// 		{
// 			command(PB, stack, info);
// 			if (stack->b[num] < info->p2)
// 				command(RA, stack, info);
// 		}
// 	}
// 	a_stack_sort(stack, info->pa - info->ra);
// 	sort_rr(stack, info);
// 	a_stack_sort(stack, info->ra);
// 	b_stack_sort(stack, info->rb, info);
// }

// void	sort_rr(t_stack *stack, t_info *info)
// {
// 	size_t	i;

// 	i = -1;
// 	while (++i < info->ra && i < info->rb)
// 	{
// 		command(RRA, stack, info);
// 		command(RRB, stack, info);
// 	}
// 	while (i++ < info->ra)
// 		command(RA, stack, info);
// 	while (i++ < info->rb)
// 		command(RRB, stack, info);
// }

// void	mini_sort(t_stack *stack, t_info *info, size_t num, t_set flag)
// {
// 	if (num == 1)
// 		return ;
// 	else if (num == 2)
// 		two_sort(stack, flag);
// 	else
// 	{
// 		if (flag == STACK_A)
// 		{
// 			if (stack->a_len == num)
// 				a_three_only(stack, info, stack->a_len - 1);
// 			// else
// 			// 	a_three_another(stack, info, stack->a_len - 1);
// 		}
// 		else if (flag == STACK_B)
// 		{
// 			if (stack->b_len == num)
// 				b_three_only(stack, info, stack->b_len - 1);
// 			// else
// 			// 	b_three_another(stack, info, stack->b_len - 1);
// 		}
// 	}
// }

// void	hard_sort(t_stack *stack, t_info *info, size_t num, t_set flag)
// {
// 	if (num <= 3)
// 		mini_sort(stack, info, num, flag);
// 	else
// 	{
// 		if (flag == STACK_A)
// 		{
// 			if (stack->a_len == num)
// 				hard_a_only(stack, info, num);
// 			// else
// 			// 	hard_a_another(stack, info, num);
// 		}
// 		else
// 		{
// 			if (stack->b_len == num)
// 				hard_b_only(stack, info, num);
// 			// else
// 			// 	hard_b_another(stack, info, num);
// 		}
// 	}
// }
