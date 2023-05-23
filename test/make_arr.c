#include "../push_swap.h"
#include <stdio.h>

int	*make_arr(t_stack *stack, t_set flag, size_t num)
{
	int		*arr;
	size_t	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * num);
	while (i < num)
	{
		arr[i] = stack->a[stack->a_len - num - 1 - i];
		i++;
	}
	return (arr);
}

int	main()
{
	t_stack stack;

	stack.a = malloc(sizeof(int) * 10);
	stack.a_len = 10;
	for (int i = 0; i < 10; i++)
		stack.a[i] = i;
	for (int i = 0; i < 10; i++)
		printf("%d ", stack.a[i]);
	int	*arr;
	arr = make_arr(&stack, STACK_A, 5);
	printf("\n");
	for (int i = 0; arr[i]; i++)
		printf("%d ", arr[i]);
	printf("\n");
}