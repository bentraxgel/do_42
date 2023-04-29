/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/04/29 02:25:37 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//	write(2, "ERROR\n", 6); //TODO 함수종료

int	main(int argc, char *argv[])
{
	int		i = 0;
	char	*arg;
	char	*space;
	int		*num;

	space = " ";
	if (argc == 1)
		return (0);
	while (argv[++i])
	{
		arg = ft_strjoin_free(arg, argv[i]);
		arg = ft_strjoin_free(arg, space);
	}
	// 문자 -> 숫자로 바꿔서 하나씩 담기.
	num = my_atoi(argv)
	my_atoi()
	printf("arg : %s\n", arg);
	return (0);
}
