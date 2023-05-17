/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:36:14 by seok              #+#    #+#             */
/*   Updated: 2023/05/17 23:14:29 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	my_error(void) //TODO ㅈㅏ료형 void에서 int로 바꿔본
{
	write(2, "ERROR\n", 6);
	exit(FALSE);
}

int	*my_indexing(int *arr, size_t len)
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
			if (arr[i] > arr[j])
				tmp[i] += 1;
			j++;
		}
		i++;
	}
	while (--i >= 0)
		arr[i] = tmp[i];
/*
왜이랬냐면, arr = tmp로 했더니 다른 함수에서 malloc한거라 그런지
main에서 stack.b할당하니까 tmp랑 같은 주소를 가져버려서 이렇게 바꿈.
*/
	free(tmp);
	return (arr);
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
