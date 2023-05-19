/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:03:10 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 00:48:42 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//r, rr둘 다 매개변수로 stack->x_len을 int len으로 받음.
void	r_command(t_stack *stack, int flag, size_t idx)
{
	int	top;

	if (flag == STACK_A && stack->a_len > 1)
	{
		top = stack->a[idx];
		while (idx)
		{
			stack->a[idx] = stack->a[idx - 1];
			idx--;
		}
		stack->a[idx] = top;
		ft_lstadd_back(&stack->command, ft_lstnew("ra\n"));
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		top = stack->b[idx];
		while (idx)
		{
			stack->b[idx] = stack->b[idx - 1];
			idx--;
		}
		stack->b[idx] = top;
		ft_lstadd_back(&stack->command, ft_lstnew("rb\n"));
	}
}

void	rr_command(t_stack *stack, int flag, size_t idx)
{
	int		bottom;
	size_t	i;

	i = -1;
	if (flag == STACK_A && stack->a_len > 1)
	{
		bottom = stack->a[0];
		while (++i < idx)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = bottom;
		ft_lstadd_back(&stack->command, ft_lstnew("rra\n"));
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		bottom = stack->b[0];
		while (++i < idx)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = bottom;
		ft_lstadd_back(&stack->command, ft_lstnew("rrb\n"));
	}
}

void	p_command(t_stack *stack, int flag)
{
	int		tmp;

	if (flag == STACK_A && stack->a_len > 0)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a[stack->a_len - 1] = 0;
		stack->a_len--;
		stack->b[stack->b_len] = tmp;
		stack->b_len++;
		ft_lstadd_back(&stack->command, ft_lstnew("pb\n"));
	}
	else if (flag == STACK_B && stack->b_len > 0)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b[stack->b_len - 1] = 0;
		stack->b_len--;
		stack->a[stack->a_len] = tmp;
		stack->a_len++;
		ft_lstadd_back(&stack->command, ft_lstnew("pa\n"));
	}
}

void	s_command(t_stack *stack, int flag)
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
