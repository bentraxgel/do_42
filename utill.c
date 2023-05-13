/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:36:14 by seok              #+#    #+#             */
/*   Updated: 2023/05/13 22:26:11 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	my_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int	*ft_indexing(int *arr, size_t len)
{
	printf("\nINDEX\n");
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = ft_calloc(len, sizeof(int));
	// tmp = (int *)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
		printf("tmp[%d] : %d\n", i, tmp[i]);
	printf("\nY\n");
	// ft_memset(tmp, 0, len);
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			printf("arr[i %d] : %d\tarr[j %d] : %d\n", i, arr[i], j, arr[j]);
			if (arr[i] > arr[j]){
				printf("In\t");
				printf("tmp[%d] : %d\n", i, tmp[i]);
				tmp[i] += 1;
				printf("tmp[%d] : %d\n", i, tmp[i]);
			}
			j++;
		}
		printf("END_tmp[i %d] : %d\n", i, tmp[i]);
		i++;
	}
	// free(arr);
	arr = tmp;
	free(tmp);
	// return (arr);
	return (arr);
}