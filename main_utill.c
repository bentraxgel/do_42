/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:36:14 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 17:26:29 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	my_error(void) //TODO ㅈㅏ료형 void에서 int로 바꿔본
{
	write(2, "ERROR\n", 6);
	exit(FALSE);
}

void	a_stack_indexing(t_stack *stack, int start, int len)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = ft_calloc(len + 1, sizeof(int));
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack->a[start + i] > stack->a[start + j])
				tmp[i] += 1;
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < len)
		stack->a[start + i] = tmp[i];
	free(tmp);
}

void	b_stack_indexing(t_stack *stack, int start, int len)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = ft_calloc(len + 1, sizeof(int));
	while(i < len)
	{
		j = 0;
		while ( j < len)
		{
			if (stack->b[start + i] > stack->b[start + j])
				tmp[i] += 1;
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < len)
		stack->b[start + i] = tmp[i];
	free(tmp);
}

int	sort_check(int *arr, size_t len)
{
	printf("check sort\n");
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (arr[i] >= arr[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	duplicate_check(int *arr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if (arr[i] == arr[j])
				return(FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
