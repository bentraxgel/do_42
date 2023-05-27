/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:35:00 by seok              #+#    #+#             */
/*   Updated: 2023/05/27 17:54:37 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_stack_sort(t_stack *stack, size_t num, t_info *info)//ra한 길이
{
	printf("a_stack_sort\n");
	int		target;
	size_t	i;

	if (stack->b_len == 0 && sort_check(stack->a, stack->a_len) == TRUE)
		return ;
	// if (num != 0 && num <= 6)
	if (num <= 6)
	{
		hard_sort(stack, info, num, STACK_A);
		return ;
	}
	// if (num != 0)
		save_pivot(stack, info, STACK_A, num);
	// num--;
	i = 1;
	while (info->ra + info->pb != num)
	{
		target = stack->a[num - i];
		printf("\n-----------------------");
		printf("\n|i : %zu|\t|num : %zu|\t=|%lu|", i, num, num - i);
		printf("\np1 : %d\tp2 : %d\na[%zu] : %d\n", info->p1, info->p2, num - i, stack->a[num - i]);
		if (info->p2 < target)
			command(RA, stack, info);
		else
		{
			command(PB, stack, info);
			printf("<<<p1 : %d\t a[%zu] : %d\n", info->p1, num, target);
			if (info->p1 < target)
			{
				if (stack->b_len > 1)
					command(RB, stack, info);
				else
					info->rb++;
			}
			i++;
		}
	}
	sort_rr(stack, info);
	printf("ra : %d\tpb : %d\trb : %d\n", info->ra, info->pb, info->rb);
	a_stack_sort(stack, info->ra, info);
	b_stack_sort(stack, info->pb, info);
	b_stack_sort(stack, info->pb - info->rb, info);
}

void	b_stack_sort(t_stack *stack, size_t num, t_info *info)
{
	printf("b_stack_sort\n");
	size_t	i;
	int		target;

	if (num <= 6)
	{
		printf("before hard sort\n");
		hard_sort(stack, info, num, STACK_B);
		printf("after hard sort\n");
		while (num--)
			p_command(stack, info, STACK_B);
		return ;
	}
	i = 1;
	save_pivot(stack, info, STACK_B, num);
	while (info->ra + info->pb != num)
	{
		target = stack->b[num - i];
		if (target <= info->p1)
			command(RB, stack, info);
		else
		{
			command(PA, stack, info);
			if (target <= info->p2)
				command(RA, stack, info);
		}
	}
	a_stack_sort(stack, info->pa - info->ra, info);
	sort_rr(stack, info);
	a_stack_sort(stack, info->ra, info);
	b_stack_sort(stack, info->rb, info);
}

void	sort_rr(t_stack *stack, t_info *info)
{
	size_t	i;

	i = -1;
	while (++i < info->ra && i < info->rb)
	{
		printf("i : %zu\tra : %d\trb : %d\n", i, info->ra, info->rb);
		command(RRA, stack, info);
		command(RRB, stack, info);
	}
	while (i < info->ra)
	{
		command(RRA, stack, info);
		i++;
	}
	while (i < info->rb){
		command(RRB, stack, info);
		i++;
		}
}

void	mini_sort(t_stack *stack, t_info *info, size_t num, t_set flag)
{
	if (num == 1)
		return ;
	else if (num == 2)
		two_sort(stack, flag, info);
	else
	{
		if (flag == STACK_A)
		{
			if (stack->a_len == num)
				a_three_only(stack, info, stack->a_len - 1);
			else
				a_three_another(stack, info, stack->a_len - 1);
		}
		else if (flag == STACK_B)
		{
			if (stack->b_len == num)
				b_three_only(stack, info, stack->b_len - 1);
			else
				b_three_another(stack, info, stack->b_len - 1);
		}
	}
}

void	hard_sort(t_stack *stack, t_info *info, size_t num, t_set flag)
{
	printf("hard_sort\tnum : %zu\n", num);
	if (num <= 3)
		mini_sort(stack, info, num, flag);
	else
	{
		printf("\tNO 3\n");
		if (flag == STACK_A)
		{
			if (stack->a_len == num)
				hard_a_only(stack, info, num);
			else
				hard_a_another(stack, info, num);
		}
		else
		{
			printf("else\n");
			if (stack->b_len == num)
				hard_b_only(stack, info, num);
			else
				hard_b_another(stack, info, num);
		}
	}
}
