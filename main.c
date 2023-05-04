/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/05/04 13:16:53 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. 스택 구현 양방향 리스트로 진행? 양방향으로 지니행해야하는 이유에 대해 생각해보자
2. 스택, 큐, 덱에 대해 공부하기 - 차이가 뭘까
*/
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*arg;
	char	*space;
	char	**word;
	int		*num;

	i = 0;
	space = " ";
	if (argc == 1)
		return (0);
	while (argv[++i])
	{
		arg = ft_strjoin_free(arg, argv[i]);
		arg = ft_strjoin_free(arg, space);
	}
	word = ft_split(arg, ' ');
	i = 0;
	while (word[i])
		i++;
	num = (int *)malloc(sizeof(int *) * (i + 1));
	while (--i >= 0)
		num[i] = ft_atoi_pro(word[i]);
	for (int i = 0; i < 5; i++)
		printf("num[%d] : %d\n", i, num[i]);
	return (0);
}
