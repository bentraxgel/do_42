/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/04/28 08:41:36 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. 스택 구현 양방향 리스트로 진행? 양방향으로 지니행해야하는 이유에 대해 생각해보자
2. 스택, 큐, 덱에 대해 공부하기 - 차이가 뭘까
*/
#include "push_swap.h"
#include <stdio.h>

//	write(2, "ERROR\n", 6); //TODO 함수종료

int	main(int argc, char **argv)
{
	int		i = 0;
	char	*arg;
	char	*space;

	space = " ";
	if (argc == 1)
		return (0);
	while (argv[++i])
	{
		arg = ft_strjoin_free(arg, argv[i]);
		arg = ft_strjoin_free(arg, space);
	}
	printf("arg : %s\n", arg);
	return (0);
}
