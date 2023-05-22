/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:42:16 by seok              #+#    #+#             */
/*   Updated: 2023/05/22 16:36:01 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_pivot(t_stack *stack, t_info *info, t_set flag, size_t num)
{
	// int	*arr;
	// if (flag == STACK_A)
	// {
	// 	arr = ft_substr(stack->a, stack->a_len - num, num);
	// 	/* sort */
	// }
	// else
	// {
	// 	arr = ft_substr(stack->a, stack->a_len - num, num);
	// 	/* sort */		
	// }
	info->p1 = stack->a[num / 3];
	info->p2 = stack->a[num / 3 * 2];
	// info->p1 = arr[num / 3];
	// info->p2 = arr[num / 3 * 2];
	reset_info(info);
	
}
// void	save_pivot(size_t start, size_t len, t_info *info)
// {
// }

// void	mini_pivot(t_stack *stack, t_info *info, t_set flag, size_t num)
// {
// 	int	*arr;

// 	if (flag == STACK_A)
// 	{
// 		arr = ft_substr(stack->a, stack->a_len - num, num);
// 		/* sort */
// 	}
// 	else
// 	{
// 		arr = ft_substr(stack->b, stack->b_len - num, num);
// 		/* sort */
// 	}
// 	if (num % 2 == 0)
// 	{
// 		info->p0 = arr[num / 2];
// 		info->num = num / 2;
// 	}
// 	else
// 	{
// 		info->p0 = arr[(num - 1) / 2];
// 		info->num = (num - 1) / 2;
// 	}
// 	reset_info(info);
// }

void	reset_info(t_info *info)
{
	info->ra = 0;
	info->rb = 0;
	info->pa = 0;
	info->pb = 0;
	info->a = 0;
	info->b = 0;
	
}
