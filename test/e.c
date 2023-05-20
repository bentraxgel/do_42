#include "../push_swap.h"

void	four_sort(t_stack *stack, int idx)
{
	int	i;
	int pb;
	int	ra;

	i = -1;
	pb = 0;
	ra = 0;
	printf("indexing\n");
	a_stack_indexing(stack, stack->a_len - 4, 4);	
	for (int i = stack->a_len; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack->a[i]);

	while (++i < 4)
	{
		printf("stack->a[%lu] : %d\n", stack->a_len - 1, stack->a[stack->a_len - 1]);
		if (stack->a[stack->a_len - 1] == 0 || stack->a[stack->a_len - 1] == 1)
		{
			 printf("\tp do\n");
			p_command(stack, STACK_A);
			pb++;
		}
		else
		{
			printf("\tr do\n");
			r_command(stack, STACK_A, stack->a_len - 1);
			ra++;
		}
		printf("while\n");
		for (int i = idx; i >= 0; i--)
			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
		printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
	}
	printf("\ncommand\n");
	while (ra--)
		rr_command(stack, STACK_A, stack->a_len - 1);
	printf("\n");
	two_sort(stack, STACK_A, stack->a_len -1);
	for (int i = idx; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
	printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
	two_sort(stack, STACK_B, stack->b_len -1);
	for (int i = idx; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
	printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
	while (pb--)
		p_command(stack, STACK_B);
}

int	main()
{
	t_stack stack;
	int		num = 10;

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
		printf("a[%d] : %d\n", i, stack.a[i]);
	four_sort(&stack, num);
	printf("a_sort\n\n");
	for (int i = num; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack.a[i]);
}