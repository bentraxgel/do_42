/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:10:50 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 03:30:37 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a_stack : 오름차순 ascending sort
// void	a_stack_sort(t_stack *stack)
void	a_stack_sort(t_stack *stack, int num) //num == stack.a_len 갯수
{
	t_info	info;
	int		i;

	if (stack->b_len == 0 && sort_check(stack->a, stack->a_len) == TRUE) //TODO 확실해?
		return ;
	if (1 < num && num <= 5)
	{
		hard_sort(stack->a_len, STACK_A, stack);
		return ;
	}
	// my_pivot(0, stack->a_len, &info);
	my_pivot(stack->a[stack->a_len - num], stack->a[num], &info);
	printf("a_p1 : %d\n", info.p1);
	printf("a_p2 : %d\n", info.p2);
	while (--num >= 0)
	{
		if (info.p2 <= stack->a[num])
		{
			r_command(&stack, STACK_A, stack->a_len);
			info.ra++;
		}
		else
		{
			p_command(&stack, STACK_A);
			info.pb++;
			if (info.p1 <= stack->a[num])
			{
				r_command(&stack, STACK_B, stack->b_len);
				info.rb++;
			}
		}
	}
	i = -1;
	while (++i < info.ra && i <info.rb)
	{
		r_command(&stack, STACK_A, stack->a_len);
		r_command(&stack, STACK_B, stack->b_len);
	}
	while (i++ < info.ra)
		r_command(stack, STACK_A, stack->a_len);
	while (i++ < info.rb)
		r_command(stack, STACK_B, stack->b_len);
	//밑에도 똑같은 역할하는 반복문 있음. 함수 만들자

	a_stack_sort(&stack, info.ra);
	b_stack_sort(&stack, info.rb, &info);
	b_stack_sort(&stack, info.pb - info.rb, &info);
}

//b_stack : descending sort
void	b_stack_sort(t_stack *stack, int num, t_info *info)
{
	int	i;

	i = -1;
	if (1 < num && num <= 5)
	{
		hard_sort(stack->b_len, STACK_B, stack);
		while(num--)
			p_command(stack, STACK_B);
		return ;
	}
	my_pivot(stack->b[stack->b_len - num], stack->b[num], info);
	while (--num >= 0)
	{
		if (stack->a[num] < info->p1)
		{
			r_command(stack, STACK_B, stack->b_len);
			info->rb++;
		}
		else
		{
			p_command(stack, STACK_B);
			info->pa++;
			if (stack->b[num] < info->p2)
			{
				r_command(stack, STACK_A, stack->a_len);  //num == idx
				info->ra++;
			}
		}
	}
	a_stack_sort(stack, info->pa - info->ra);
	
	while (++i < info->ra && i < info->rb)
	{
		r_command(stack, STACK_A, stack->a_len);
		r_command(stack, STACK_B, stack->b_len);
	}
	while (i++ < info->ra)
		r_command(stack, STACK_A, stack->a_len);
	while (i++ < info->rb)
		r_command(stack, STACK_B, stack->b_len);
	a_stack_sort(stack, info->ra);
	b_stack_sort(stack, info->rb, info);
}
