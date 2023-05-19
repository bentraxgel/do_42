#include "../push_swap.h"

void	four_sort(t_stack *stack, int idx)
{
	int	i;
	int pb;

	i = -1;
	pb = 0;
	a_stack_indexing(stack, idx - 4, 4);
	while (++i < 4)
	{
		if (stack->a[idx + i] <= 1)
		{
			p_command(stack, STACK_A);
			pb++;
		}
		else
			r_command(stack, STACK_A, stack->a_len);
	}
	two_sort(stack, STACK_A, stack->a_len);
	two_sort(stack, STACK_B, stack->b_len);
	while (pb--)
		p_command(stack, STACK_B);
}

int	main()
{
	t_stack stack;

	stack.a = malloc(sizeof(int *) * 10);
	for (int i = 0; i < 10; i++)
	{
		stack.a[i] = 10 + i; printf("a[%d] : %d\n", i, stack.a[i]);
	}
	printf("a_sort\n\n");
	four_sort(&stack, 10 - 1);
	for (int i = 0; i < 10; i++)
		printf("a[%d] : %d\n", i, stack.a[i]);
}