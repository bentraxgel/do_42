/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:24:55 by seok              #+#    #+#             */
/*   Updated: 2023/05/17 23:39:08 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_info *stack, int flag)
{
	int	i;

	i = 0;
	if (flag == STACK_A)
	{
		if (stack->a[i] < stack->a[i + 1])
			return ;
		else if (stack->a[i] > stack->a[i + 1])
			s_command(stack, STACK_A);
	}
	if (flag == STACK_B)
	{
		if (stack->b[i] > stack->b[i + 1])
			return ;
		else if (stack->b[i] > stack->b[i + 1])
			s_command(stack, STACK_B);
	}
}

