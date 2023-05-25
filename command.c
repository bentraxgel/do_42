/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:03:10 by seok              #+#    #+#             */
/*   Updated: 2023/05/26 02:43:34 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	command(t_cmd cmd, t_stack *stack, t_info *info)
{
	if (cmd == RA){
		printf("RA\n");
		r_command(stack, info, STACK_A, stack->a_len);
	}
	else if (cmd == RB){
		printf("RB\n");
		r_command(stack, info, STACK_B, stack->b_len);
	}
	else if (cmd == RRA){
		printf("RRA\n");
		rr_command(stack, STACK_A, stack->a_len - 1);
	}
	else if (cmd == RRB){
		printf("RRB\n");
		rr_command(stack, STACK_B, stack->b_len - 1);
	}
	else if (cmd == PA){
		printf("PA\n");
		p_command(stack, info, STACK_A);
	}
	else if (cmd == PB){
		printf("PB\n");
		p_command(stack, info, STACK_B);
	}
	else if (cmd == SA){
		printf("SA\n");
		s_command(stack, STACK_A);
	}
	else if (cmd == SB){
		printf("SB\n"); 
		s_command(stack, STACK_B);
	}
	else
		return (0);
	printf("<<<command>>>\n"); //TODO del_print
	for (int i = stack->total_len - 1; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
	printf("a_len : %zu\tb_len : %zu\n", stack->a_len, stack->b_len);

	return (1);
}

void	r_command(t_stack *stack, t_info *info, t_set flag, size_t len)
{
	size_t	va_top;

	if (flag == STACK_A && stack->a_len > 1)
	{
		va_top = stack->a[len - 1];
		while (--len)
			stack->a[len] = stack->a[len - 1];
		stack->a[len] = va_top;
		ft_lstadd_back(&stack->command, ft_lstnew("ra\n"));
		info->ra++;
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		va_top = stack->b[stack->b_len - 1];
		while (--len)
			stack->b[len] = stack->b[len - 1];
		stack->b[len] = va_top;
		ft_lstadd_back(&stack->command, ft_lstnew("rb\n"));
		info->rb++;
	}
}

void	rr_command(t_stack *stack, t_set flag, size_t top)
{
	size_t	va_bottom;
	size_t	i;

	i = -1;
	if (flag == STACK_A && stack->a_len > 1)
	{
		va_bottom = stack->a[0];
		while (++i < top)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = va_bottom;
		ft_lstadd_back(&stack->command, ft_lstnew("rra\n"));
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		va_bottom = stack->b[0];
		while (++i < top)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = va_bottom;
		ft_lstadd_back(&stack->command, ft_lstnew("rrb\n"));
	}
}

void	p_command(t_stack *stack, t_info *info, t_set flag)
{
	size_t	tmp;

	if (flag == STACK_B && stack->a_len > 0)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a[stack->a_len - 1] = 0;
		stack->a_len--;
		stack->b[stack->b_len] = tmp;
		stack->b_len++;
		ft_lstadd_back(&stack->command, ft_lstnew("pb\n"));
		info->pb++;
		printf("\t>>>>>pb : %d\n", info->pb);
	}
	else if (flag == STACK_A && stack->b_len > 0)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b[stack->b_len - 1] = 0;
		stack->b_len--;
		stack->a[stack->a_len] = tmp;
		stack->a_len++;
		ft_lstadd_back(&stack->command, ft_lstnew("pa\n"));
		info->pa++;
	}
}

void	s_command(t_stack *stack, t_set flag)
{
	size_t	tmp;

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
