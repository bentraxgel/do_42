#include "../push_swap.h"

void	a_three(t_stack *stack, t_info *info, int top)
{
	a_stack_indexing(stack, stack->a_len - 3, 3);

	if (stack->a[top] > stack->a[top - 1] && stack->a[top] > stack->a[top - 2])
	{
		command(RA, stack, info);
		if (stack->a[top - 1] > stack->a[top - 2])
			command(SA, stack, info);
	}
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
	{
		command(RRA, stack, info);
		command(SA, stack, info);
	}
	else if (stack->a[top] > stack->a[top - 1] \
			&& stack->a[top] < stack->a[top - 2])
			command(SA, stack, info);
	else if (stack->a[top] < stack->a[top - 1] \
			&& stack->a[top] > stack->a[top - 2])
			command(RRA, stack, info);
}


void	b_three_sort(t_stack *stack, t_info *info, int top)
{
	b_stack_indexing(stack, stack->b_len - 3, 3);

	if (stack->b[top] < stack->b[top - 1] && stack->b[top] < stack->b[top - 2])
	{
		if (stack->b[top - 1] < stack->b[top - 2])
		{
			command(SB, stack, info);
			command(RRB, stack, info);
		}
		else
			command(RB, stack, info);
	}
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
	{
		command(RRB, stack, info);
		command(SB, stack, info);
	}
	else if (stack->b[top] > stack->b[top - 1] \
			&& stack->b[top] < stack->b[top - 2])
		command(RRB, stack, info);
	else if (stack->b[top] < stack->b[top - 1] \
			&& stack->b[top] > stack->b[top - 2])
		command(SB, stack, info);
}

int	q_main()
{
	t_stack stack;
	t_info	info;
	int		num = 10;

	stack.a = malloc(sizeof(int *) * 10);
	stack.a_len = 0;
	stack.b = malloc(sizeof(int *) * 10);
	stack.b_len = num;
	stack.command = ft_lstnew("start\n");
	// for (int i = 0; i < num; i++)
	// {
	// 	stack.a[i] = 10 - i; printf("a[%d] : %d\n", i, stack.a[i]);
	// }
	for (int i = 0; i < num; i++)
	{
		if (i % 2)
			stack.b[i] = 10 + i;
		else
			stack.b[i] = i;
		printf("%d ", stack.b[i]);
	}
	printf("\n");
	// stack.a[4] = 10;
	// stack.a[3] = 15;
	// stack.a[2] = 12;
	// stack.a[1] = 17;
	// stack.a[0] = 11;
	for (int i = num; i >= 0; i--)
		printf("b[%d] : %d\n", i, stack.b[i]);
	printf("sort\n");
	b_three_sort(&stack, &info, num);
	printf("b_sort\n\n");
	for (int i = num; i >= 0; i--)
		printf("b[%d] : %d\n", i, stack.b[i]);
	return (0);
}

int	main()
{
	t_stack stack;
	t_info	info;
	int		num = 10;

	stack.a = malloc(sizeof(int *) * 10);
	stack.a_len = num;
	stack.b = malloc(sizeof(int *) * 10);
	stack.b_len = num;
	stack.command = ft_lstnew("start\n");
	// for (int i = 0; i < num; i++)
	// {
	// 	stack.a[i] = 10 - i; printf("a[%d] : %d\n", i, stack.a[i]);
	// }
	for (int i = 0; i < num; i++)
	{
		if (i % 2)
			stack.a[i] = 10 + i;
		else
			stack.a[i] = i + 1;
		printf("%d ", stack.a[i]);
	}
	for (int i = 0; i < num; i++)
	{
		if (i % 2)
			stack.b[i] = 10 + i;
		else
			stack.b[i] = i;
		printf("%d ", stack.b[i]);
	}
	printf("\n");
	// stack.a[4] = 10;
	// stack.a[3] = 15;
	// stack.a[2] = 12;
	// stack.a[1] = 17;
	// stack.a[0] = 11;
	for (int i = num; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
	printf("sort\n");
	// a_three_only(&stack, &info, stack.a_len - 1);
	a_three_another(&stack, &info, stack.a_len - 1);
	b_three_another(&stack, &info, stack.b_len - 1);
	printf("\na_sort\n");
	for (int i = num; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
	return (0);
}