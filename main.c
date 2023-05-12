/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/05/12 23:17:50 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	stack.a_len = i;
	stack.b_len = 0;
	int	len = i; //TODO 이따가 이거 없이 한번 해보기 될거야 무조건!
	stack.a = (int *)malloc(sizeof(int *) * (i + 1));
	stack.sort = (int *)malloc(sizeof(int *) * (i + 1));
	i = -1;
	while (word[++i])
		stack.a[len - i - 1] = ft_atoi_pro(word[i]);
	stack.sort = stack.a;
//중복된 숫자가 있는지 확인
	if (ft_duplicate) 
//등수메기기

	//얘는 만약 정렬이 다 돼있을경우엔 필요없기때문에 생각해서 위치 두자.
	stack.b = (int *)malloc(sizeof(int *) * (i + 1));
	/**/
		for (int i = 0; i < 5; i++)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
		printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);
		// rr_command(&stack, STACK_A, stack.a_len);
		s_command(&stack, STACK_A);
		printf("\n");
		printf("\ns_command\n");
		for (int i = 0; i < 5; i++)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
		printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);
		
		p_command(&stack, STACK_A);
		printf("\n");
		printf("\np_command\n");
		for (int i = 0; i < 5; i++)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
		printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);

		p_command(&stack, STACK_A);
		printf("\n");
		for (int i = 0; i < 5; i++)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
		printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);
		printf("<<<b_len : %zu>>>>>>\n", stack.b_len);
		
		r_command(&stack, STACK_A, stack.a_len);
		r_command(&stack, STACK_B, stack.b_len);
		// s_command(&stack, STACK_A);
		s_command(&stack, STACK_B);
		rr_command(&stack, STACK_A, stack.a_len);
		rr_command(&stack, STACK_B, stack.b_len);
		
		printf("\np_command\n");
		printf("\n");
		for (int i = 0; i < 5; i++)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
		printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);

		p_command(&stack, STACK_B);
		printf("\np_command\n");
		printf("\n");
		for (int i = 0; i < 5; i++)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
		printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);
		p_command(&stack, STACK_B);
		printf("\np_command\n");
		printf("\n");
		for (int i = 0; i < 5; i++)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
		printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);
		
		func(stack.command);
		printf("\noptimization\n");
		print_command(stack.command);
		// func(stack.command);
		// for (int i = 0; i < 5; i++)
		// 	printf("%s\n", stack.command.content);
	/**/
	return (0);
}
