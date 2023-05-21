/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:14:53 by seok              #+#    #+#             */
/*   Updated: 2023/05/22 04:29:32 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_pivot(size_t start, size_t len, t_info *info)
{
	info->p1 = ((len - start) / 3) + start;
	info->p2 = ((len - start) / 3 * 2) + start;
	info->pa = 0;
	info->pb = 0;
	info->ra = 0;
	info->rb = 0;
}

void	hard_sort(t_stack *stack, t_info *info, size_t num, t_set flag)
{
	int	a;
	int	b;
	int	i;

	a = 3;
	b = num - 3;
	i = 0;
	if (num <= 3)
		mini_sort(stack, info, num, flag);
	else
	{
		while (i++ < b){
			command(PB, stack, info);
			printf("<<PB>>");
		}
		printf("\nbefore mini\n");
		for (int i = stack->total_len; i >= 0; i--)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
		printf("a : %d\t b : %d\n", a, b);
		mini_sort(stack, info, a, STACK_A);
		mini_sort(stack, info, b, STACK_B);
		printf("\nafter mini\n");
		for (int i = stack->total_len; i >= 0; i--)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
		printf("a : %d\t b : %d\n\n\n", a, b);
		printf("\tB_LEN : %zu\n", stack->b_len);
		while (a + b)
		{
			if (a == 0)
			{
				printf("	cmd : if a0 %d + %d =%d\n", a, b, a+b);
				b -= command(PA, stack, info);
			}
			else if (b == 0)
			{
				printf("	cmd : if b0 %d + %d =%d\n", a, b, a+b);
				a -= command(RRA, stack, info);
			}
			else if (stack->a[0] > stack->b[stack->b_len - 1])
			{
				printf("	cmd : if a- %d + %d =%d\n", a, b, a+b);
				a -= command(RRA, stack, info);
			}
			else if (stack->a[0] < stack->b[stack->b_len - 1])
			{
				printf("	cmd : if b- %d + %d =%d\n", a, b, a+b);
				b -= command(PA, stack, info);
			}
		while (i-- > 0){
			command(PA, stack, info);
			printf("%d <<PA>>\n", i);
		}
		// for (int i = stack->total_len; i >= 0; i--)
		// 	printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
		// printf("a : %d\t b : %d\n", a, b);
		}
		// while (a + b + info->ra + info->pa)
		// {
		// 	if (a == 0 && info->pa)
		// 		b -= command(PA, stack, info);
		// 	else if (b == 0 && info->ra)
		// 		a -= command(RRA, stack, info);
		// 	else if (stack->a[stack->a_len - 1] < stack->b[stack->b_len - 1])
		// 		a -= command(RA, stack, info);
		// 	else if (stack->a[stack->a_len - 1] > stack->b[stack->b_len - 1])
		// 		b -= command(PA, stack, info);
		// for (int i = stack->total_len; i >= 0; i--)
		// 	printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
		// printf("a : %d\t b : %d\n", a, b);
		// }
	}
}

void	mini_sort(t_stack *stack, t_info *info, size_t num, t_set flag)
{
	printf("\n\t<<<MINI>>>>\n");
	if (num == 1)
		return ;
	else if (num == 2)
		two_sort(stack, flag);
	else
	{
		if (flag == STACK_A)
		{
			printf("\tSTACK_A\n");
			if (stack->a_len == num)
				a_three_only(stack, info, stack->a_len - 1);
			else
				a_three_another(stack, info, stack->a_len - 1);
		}
		else if (flag == STACK_B)
		{
			printf("\tSTACK_B\n");
			printf("\tSTACK_B\n");
			if (stack->b_len == num)
				b_three_only(stack, info, stack->b_len - 1);
			else
				b_three_another(stack, info, stack->b_len - 1);
		}
	}
}

void	two_sort(t_stack *stack, t_set flag)
{
	if (flag == STACK_A)
	{
		if (stack->a[stack->a_len - 1] < stack->a[stack->a_len - 2])
			return ;
		else if (stack->a[stack->a_len - 1] > stack->a[stack->a_len - 2])
			s_command(stack, STACK_A);
	}
	else if (flag == STACK_B)
	{
		printf("two_STACK_B\n");
		if (stack->b[stack->b_len - 1] > stack->b[stack->b_len - 2])
		{
			printf("if");
			return ;
		}
		else if (stack->b[stack->b_len - 1] < stack->b[stack->b_len - 2])
			s_command(stack, STACK_B);
	}
}
