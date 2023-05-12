/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:03:10 by seok              #+#    #+#             */
/*   Updated: 2023/05/12 19:23:05 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//r, rr둘 다 매개변수로 stack->x_len을 int len으로 받음.
void	r_command(t_info *stack, int flag, size_t len)
{
	int top;

	if (flag == STACK_A && stack->a_len > 1)
	{
		top = stack->a[len - 1];
		while (--len)
			stack->a[len] = stack->a[len - 1];
		stack->a[len] = top;
		ft_lstadd_back(&stack->command, ft_lstnew("ra\n"));
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		top = stack->b[len - 1];
		while (--len)
			stack->b[len] = stack->b[len - 1];
		stack->b[len] = top;
		ft_lstadd_back(&stack->command, ft_lstnew("rb\n"));
	}
}

void	rr_command(t_info *stack, int flag, size_t len)
{
	int		bottom;
	size_t	i;

	i = -1;
	if (flag == STACK_A && stack->a_len > 1)
	{
		bottom = stack->a[0];
		while (++i < len)
			stack->a[i] = stack->a[i + 1];
		stack->a[i -1] = bottom;
		ft_lstadd_back(&stack->command, ft_lstnew("rra\n"));
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		bottom = stack->b[0];
		while (++i < len)
			stack->b[i] = stack->b[i + 1];
		stack->b[i - 1] = bottom;
		ft_lstadd_back(&stack->command, ft_lstnew("rrb\n"));
	}
}

void	p_command(t_info *stack, int flag)
{
	int		tmp;

	stack->b_len = ft_arrlen(stack->b);
	if (flag == STACK_A && stack->a_len > 0)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a_len--;
		stack->b[stack->b_len] = tmp;
		stack->b_len++;
		ft_lstadd_back(&stack->command, ft_lstnew("pa\n"));
	}
	else if (flag == STACK_B && stack->b_len > 0)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b_len--;
		stack->a[stack->a_len] = tmp;
		stack->a_len++;
		ft_lstadd_back(&stack->command, ft_lstnew("pb\n"));
	}
}

void	s_command(t_info *stack, int flag)
{
	int	tmp;

	if (flag == STACK_A && stack->a_len > 1)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a[stack->a_len -1] = stack->a[stack->a_len -2];
		stack->a[stack->a_len - 2] = tmp;
		ft_lstadd_back(&stack->command, ft_lstnew("sa\n"));
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b[stack->b_len -1] = stack->b[stack->b_len -2];
		stack->b[stack->b_len - 2] = tmp;
		ft_lstadd_back(&stack->command, ft_lstnew("sb\n"));
	}
}