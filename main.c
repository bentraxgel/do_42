/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 05:00:50 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //TODO : 지워야징


void	ft_del(t_list *lst)
{
	while (lst != NULL)
	{
		free(lst);
		lst = lst->next;
	}
}

void	func(t_list *command) //명령어 출력함수
{
	printf("func\n");
	while(command)
	{
		printf("%s", command->content);
		command = command->next;
	}
	// ft_lstclear(&command, (void *)0);
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
	t_stack	stack;

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
	stack.total_len = i; //TODO del
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
//****이 밑에 함수들 len이랑 비교할 index들 다 int로 돼있는데 그거 size_t로 바꿔야함
//중복된 숫자가 있는지 확인
	if (duplicate_check(stack.a, stack.a_len) == FALSE)
		my_error();
	// for (int i = 0; i < stack.a_len; i++)
	for (int i = stack.a_len - 1; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack.a[i]);
//등수메기기 - 이게 sort함수에 들어가도 될지도? 함수 첫 시작에!
	// stack.a = my_indexing(stack.a, stack.a_len);
	a_stack_indexing(&stack, 0, stack.a_len);
	if (sort_check(stack.a, stack.a_len) == TRUE)
	{
		free(stack.a);
		return (0);
	}
	//얘는 만약 정렬이 다 돼있을경우엔 필요없기때문에 생각해서 위치 두자.
	stack.b = (int *)ft_calloc(stack.a_len + 1, sizeof(int *));

	// for (int i = 0; i < stack.a_len; i++)
	for (int i = stack.a_len - 1; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack.a[i]);

	// two_sort(&stack, STACK_A); //TODO idx줘야함
	printf("\ntwo_sort\n\n");
	// for (int i = 0; i < stack.a_len; i++)
	rr_command(&stack, STACK_A, 2);
	p_command(&stack, STACK_A);
/*
	이제 여기서 sort해야함......!!
*/
	// a_stack_
	func(stack.command);
	for (int i = stack.a_len - 1; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack.a[i]);
	// // if (stack.a)
		free(stack.a); //왜 얘는 없어도 누수가 안나지? total주소 받아서 그런가.
	// // if (stack.b)
		free(stack.b);
		ft_del(stack.command);
	return (0);
}
