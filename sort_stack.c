/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:35:00 by seok              #+#    #+#             */
/*   Updated: 2023/05/22 05:43:06 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a_stack : 오름차순 ascending sort
// void	a_stack_sort(t_stack *stack)
void	a_stack_sort(t_stack *stack, size_t num) //num == stack.a_len 갯수
{
	t_info	info;
	size_t	i;

	if (stack->b_len == 0 && sort_check(stack->a, stack->a_len) == TRUE) //TODO 확실해?
		return ;
	if (num <= 6)
	{
		hard_a_sort(stack, &info, num, STACK_A);
		return ;
	}
	// my_pivot(0, stack->a_len, &info);
	my_pivot(stack->a[stack->a_len - num], stack->a[num], &info);
	printf("a_p1 : %d\n", info.p1);
	printf("a_p2 : %d\n", info.p2);
	while (--num >= 0)
	{
		if (info.p2 <= stack->a[num])
			command(RA, stack, &info);
		else
		{
			command(PA, stack, &info);
			if (info.p1 <= stack->a[num])
				command(RB, stack, &info);
		}
	}
	i = -1;
	while (++i < info.ra && i <info.rb)
	{
		command(RRA, stack, &info);
		command(RRB, stack, &info);
	}
	while (i++ < info.ra)
		command(RA, stack, &info);
	while (i++ < info.rb)
		command(RRB, stack, &info);
	//밑에도 똑같은 역할하는 반복문 있음. 함수 만들자

	a_stack_sort(stack, info.ra);
	b_stack_sort(stack, info.rb, &info);
	b_stack_sort(stack, info.pb - info.rb, &info);
}

//b_stack : descending sort
void	b_stack_sort(t_stack *stack, size_t num, t_info *info)
{
	size_t	i;

	i = -1;
	if (num <= 6)
	{
		hard_b_sort(stack, info, num, STACK_B);
		while (num--)
			p_command(stack, info, STACK_B);
		return ;
	}
	my_pivot(stack->b[stack->b_len - num], stack->b[num], info);
	while (--num >= 0)
	{
		if (stack->a[num] < info->p1)
			command(RB, stack, info);
		else
		{
			command(PB, stack, info);
			if (stack->b[num] < info->p2)
				command(RA, stack, info);
		}
	}
	a_stack_sort(stack, info->pa - info->ra);
	
	while (++i < info->ra && i < info->rb)
	{
		command(RRA, stack, info);
		command(RRB, stack, info);
	}
	while (i++ < info->ra)
		command(RRA, stack, info);
	while (i++ < info->rb)
		command(RRB, stack, info);
	a_stack_sort(stack, info->ra);
	b_stack_sort(stack, info->rb, info);
}
