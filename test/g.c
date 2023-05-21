#include "push_swap.h"

int	main()
{
	t_stack stack;

	stack.a = malloc(sizeof(int *) * 5);
	stack.a[0] = 0;
	stack.a[1] = 1;
	stack.a[2] = 3;
	stack.a_len = 3;
	stack.
	for(int i = 0; i < 3; i++)
		printf("a[%d] : %d\n", i, stack.a[i]);
	r_command(&stack, STACK_A, 2);
	for(int i = 0; i < 3; i++)
		printf("a[%d] : %d\n", i, stack.a[i]);
}