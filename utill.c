/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:36:14 by seok              #+#    #+#             */
/*   Updated: 2023/05/17 23:06:23 by seok             ###   ########.fr       */
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
	printf("\nINDEX\n");
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = ft_calloc(len + 1, sizeof(int));
	printf("a : %p, tmp : %p\n", arr, tmp);
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i] > arr[j]){
				printf("arr[%d] : %d\tarr[%d] : %d\n", i, arr[i], j, arr[j]);
				tmp[i] += 1;
				printf("tmp[%d] : %d\ttmp[%d] : %d\n", i, tmp[i], j, tmp[j]);
			}
			j++;
		}
		i++;
	}
	while (--i >= 0){
		printf("tmp[%d] : %d\n", i, tmp[i]);
		arr[i] = tmp[i];
	}
	free(tmp);

	return (arr);
}

// int	my_indexing1(int **arr, size_t len)
// {
// 	printf("\nINDEX\n");
// 	int	i;
// 	int	j;
// 	int	*tmp;

// 	i = 0;
// 	tmp = ft_calloc(len + 1, sizeof(int));
// 	printf("a : %p, tmp : %p\n", arr, tmp);
// 	while(i < len)
// 	{
// 		j = 0;
// 		while (j < len)
// 		{
// 			/*
// 			어떤 부분을 하고있었나면.
// 			이 함수의 결과값을 이용하여 등수메기기를 잘 했는지 못했는지 확인해서 등수메기기하다가 
// 			*/
// 			// if (*(arr + i) > *(arr + j)){
// 			if ((arr[i]) > (arr[j])){ //TODO 지금 여기서 막혔는데
// 				printf("arr[%d] : %d\tarr[%d] : %d\n", i, *(arr + i), j, *(arr +j));
// 				tmp[i] += 1;
// 				// printf("tmp[%d] : %d\ttmp[%d] : %d\n", i, tmp[i], j, tmp[j]);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	while (--i >= 0){
// 		printf("tmp[%d] : %d\n", i, tmp[i]);
// 		printf("tmp[%d] : %p\n", i, &tmp[i]);
// 		arr[i] = &tmp[i];
// 		printf("arr[%d] : %d\n", i, *arr[i]);
// 		// *(arr + i) = tmp[i];
// 	}
// 	free(tmp);
// 	if (sort_check(*arr, len) == TRUE)
// 		return (FALSE);
// 	return (TRUE);
// }

int	*indexing(int *arr, size_t len)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = malloc(sizeof(int) * len);
	tmp = arr;
	ft_bzero(arr, len);
	printf("a : %p, tmp : %p\n", arr, tmp);
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (tmp[i] > tmp[j]){
				printf("arr[%d] : %d\tarr[%d] : %d\n", i, arr[i], j, arr[j]);
				printf("tmp[%d] : %d\ttmp[%d] : %d\n", i, tmp[i], j, tmp[j]);
				arr[i] += 1;
			}
			j++;
		}
		i++;
	}
	free (tmp);
	if (sort_check(arr, len) == TRUE)
		return (0);
	// return (arr);
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