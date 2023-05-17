/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/05/17 23:06:08 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //TODO : 지워야징

void	func(t_list *command)
{
	printf("func\n");
	while(command)
	{
		printf("%s", command->content);
		command = command->next;
	}
}

void	leaks()
{
	system("leaks -q a.out");
}

int	main(int argc, char *argv[])
{
	atexit(leaks); //TODO del
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
	free(arg);

	i = 0;
	while (word[i])
		i++;
	stack.total_len = i;
	stack.a_len = i;
	stack.b_len = 0;
	stack.a = (int *)malloc(sizeof(int *) * (i + 1));
	// stack.total = (int *)malloc(sizeof(int *) * (i + 1));

	i = -1;
	while (word[++i])
		stack.a[stack.a_len - i - 1] = ft_atoi_pro(word[i]);
	while (--i >= 0)
		free(word[i]);
	free(word);

//중복된 숫자가 있는지 확인
	if (duplicate_check(stack.a, stack.a_len) == FALSE)
		my_error();
//등수메기기
	stack.a = my_indexing(stack.a, stack.a_len);
	if (sort_check(stack.a, stack.a_len) == TRUE)
	{
		free(stack.a);
		return (0);
	}
	//얘는 만약 정렬이 다 돼있을경우엔 필요없기때문에 생각해서 위치 두자.
	stack.b = (int *)ft_calloc(stack.a_len + 1, sizeof(int *));
/*
	이제 여기서 sort해야함......!!
*/
	// // if (stack.a)
		free(stack.a); //왜 얘는 없어도 누수가 안나지? total주소 받아서 그런가.
	// // if (stack.b)
		free(stack.b);
		free(stack.command); //TODO 명령어들 출력하고 free잊지말고 해야함. node들이 만들어져있기때문
	// // if (stack.total)
		// free(stack.total);
	return (0);
}
