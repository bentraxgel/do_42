/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/05/05 06:00:52 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //TODO : 지워야징

int	main(int argc, char *argv[])
{
	int		i;
	char	*arg;
	char	*space;
	char	**word;
	t_info	stack;

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
	stack.total_len = i;
	stack.a = (int *)malloc(sizeof(int *) * (i + 1));
	stack.sort = (int *)malloc(sizeof(int *) * (i + 1));
	while (--i >= 0)
		stack.a[i] = ft_atoi_pro(word[i]);
	stack.sort = stack.a;
	for (int i = 0; i < 5; i++)
		printf("num[%d] : %d\n", i, stack.a[i]);
	return (0);
}
