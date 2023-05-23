/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:42:16 by seok              #+#    #+#             */
/*   Updated: 2023/05/23 21:02:51 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr(t_stack *stack, t_set flag, size_t num)
{
	int		*arr;
	size_t	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * num);
	while (i < num)
	{
		arr[i] = stack->a[stack->a_len - num - 1 - i];
		i++;
	}
	return (arr);
}

void	save_pivot(t_stack *stack, t_info *info, t_set flag, size_t num)
{
	int	*arr;
	
	if (flag == STACK_A)
	{
		arr = make_arr(stack, flag, num);
		quickSort(arr, stack->a_len - num - 1, stack->a_len - 1);
		/* sort */
	}
	else
	{
		arr = make_arr(stack, flag, num);
		quickSort(arr, stack->b_len - num - 1, stack->b_len - 1);
		/* sort */		
	}
	for (int i = 0; i < num; i++)
		printf("arr[%d] : %d\n", i, arr[i]);
	/* 이둘은 지우고 밑의 pivot값 구하는 방식을 사용해야함 */
	// info->p1 = stack->a[num / 3];
	// info->p2 = stack->a[num / 3 * 2];
	info->p1 = arr[num / 3];
	info->p2 = arr[num / 3 * 2];
	printf("pi : %d\tp2 : %d\n", info->p1, info->p2);
	reset_info(info);
	
}
// void	save_pivot(size_t start, size_t len, t_info *info)
// {
// }

/* mini에서 info->num은 a, b로 나눴던 정보를 따로 쓰기엔 너무 길어서 num을 만들어서 ....
	차라리 반환값으로 주는것도 나쁘지 않을것같기도..?일단 이건 좀 더 시간 있을때 코드를 자세히 읽어보고 판단하자 */
void	mini_pivot(t_stack *stack, t_info *info, t_set flag, size_t num)
{
	int	*arr;

	if (flag == STACK_A)
	{
		arr = make_arr(stack, flag, num);
		/* sort */
		quickSort(arr, stack->a_len - num - 1, stack->a_len - 1);
	}
	else
	{
		arr = make_arr(stack, flag, num);
		/* sort */
		quickSort(arr, stack->a_len - num - 1, stack->a_len - 1);
	}
	if (num % 2 == 0)
	{
		info->p0 = arr[num / 2];
		info->num = num / 2;
	}
	else
	{
		info->p0 = arr[(num - 1) / 2];
		info->num = (num - 1) / 2;
	}
	reset_info(info);
}

void	reset_info(t_info *info)
{
	info->ra = 0;
	info->rb = 0;
	info->pa = 0;
	info->pb = 0;
	info->a = 0;
	info->b = 0;
	
}
