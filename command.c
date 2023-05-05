/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:03:10 by seok              #+#    #+#             */
/*   Updated: 2023/05/05 09:16:28 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//r, rr둘 다 매개변수로 stack->x_len을 int len으로 받음.
void	r_command(t_info *stack, int flag, size_t len)
{
	//생각해보니 이친구는 이미 값이 들어있을듯
	//stack->b_len = ft_strlen(stack->a);

	//TODO lstadd되는지 test해볼것
	int top;

	if (flag == STACK_A)
	{
		top = stack->a[len - 1];
		while (--len)
			stack->a[len] = stack->a[len - 1];
		stack->a[len] = top;
		if (stack->a_len > 1)
			ft_lstadd_back(stack->command, ft_lstnew("ra\n"));
	}
	else if (flag == STACK_B)
	{
		top = stack->b[len - 1];
		while (--len)
			stack->b[len] = stack->b[len - 1];
		stack->b[len] = top;
		if (stack->b_len > 1)
			ft_lstadd_back(stack->command, ft_lstnew("rb\n"));
	}
	
}

void	rr_command(t_info *stack, int flag, size_t len)
{
	int 	bottom;
	size_t	i;

	i = -1;
	if (flag == STACK_A)
	{
		bottom = stack->a[len - 1];
		while (++i < len)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = bottom;
		if (stack->a_len > 1)
			ft_lstadd_back(stack->command, ft_lstnew("rra\n"));
	}
	else if (flag == STACK_B)
	{
		bottom = stack->b[len - 1];
		while (++i < len)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = bottom;
		if (stack->b_len > 1)
			ft_lstadd_back(stack->command, ft_lstnew("rrb\n"));
	}
}

void	p_command(t_info *stack, int flag)
{
	int		tmp;

	if (flag == STACK_A)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a_len--;
		stack->b[stack->b_len] = tmp;
		stack->b_len++;
	}
	else if (flag == STACK_B)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b_len--;
		stack->a[stack->a_len] = tmp;
		stack->a_len++;
	}
}

//TODO 이놈도 되는지 확인 swap
//STACK_B에 대해서도 만들어야함
void	s_command(t_info *stack, int flag)
{
	int	tmp;

	tmp = stack->a[stack->a_len - 1];
	stack->a[stack->a_len -1] = stack->a[stack->a_len -2];
	stack->a[stack->a_len - 2] = tmp;
}