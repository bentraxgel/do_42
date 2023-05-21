#include "../push_swap.h"

void	a_multiple_sort(t_stack *stack, t_info *info, int num)
{
	int	i = 0;
	int	a = 3;
	int	b = num - 3;
	while (i++ < b)
	{
		command(PB, stack, info);
		hard_sort(stack, info, a, STACK_A);
		hard_sort(stack, info, b, STACK_B);
		printf("\nhard_sort\n");
		for (int i = num; i >= 0; i--)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
		printf("a : %d\t b : %d\n", a, b);
	}
	printf("\n\nwhile\n");
	while (a + b)
	{
		if (a == 0)
			b -= command(PA, stack, info);
		else if (b == 0)
			a -= command(RRA, stack, info);
		else if (stack->a[0] > stack->b[stack->b_len - 1])
			a -= command(RRA, stack, info);
		else if (stack->a[0] < stack->b[stack->b_len - 1])
			b -= command(PA, stack, info);
	for (int i = num; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
	printf("a : %d\t b : %d\n", a, b);
	}
}

int	main()
{
	t_stack stack;
	t_info	info;
	int		num = 7;

	stack.a = malloc(sizeof(int *) * 10);
	stack.a_len = num;
	stack.b = malloc(sizeof(int *) * 10);
	stack.b_len = 0;
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
			stack.a[i] = i;
		printf("%d ", stack.a[i]);
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
	a_multiple_sort(&stack, &info, 4);
	// a_four(&stack, &info);
	// b_four(&stack, &info);
	printf("a_sort\n\n");
	for (int i = num; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
	return (0);
}