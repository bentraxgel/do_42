/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/04/30 16:15:57 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
