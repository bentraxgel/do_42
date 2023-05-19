#include "../push_swap.h"
#include <stdio.h>

void	func1(t_stack *stack)
{
	stack->a_len = 1000;
}

void	func(t_stack *stack)
{
	stack->a[0] = 20;
	stack->a[3] = 123;
	stack->a_len = 300;
	func1(stack);
}

int	main()
{
	t_stack stack;

	stack.a = malloc(sizeof(int) * 10);
	stack.b = malloc(sizeof(int) * 10);
	stack.a[0] = 10;
	stack.a[1] = 100;

	stack.a_len = 80;

	printf("len : %zu\n", stack.a_len);
	// for(int i = 0; i < 5; i++)
	// 	printf("a[%d] : %d\n", i, stack.a[i]);
	// stack.b = stack.a;
	// for(int i = 0; i < 5; i++)
	// 	printf("b[%d] : %d\n", i, stack.b[i]);
	// printf("\n\n");
	func(&stack);
	printf("len : %zu\n", stack.a_len);
	// for(int i = 0; i < 5; i++)
	// 	printf("a[%d] : %d\n", i, stack.a[i]);
}