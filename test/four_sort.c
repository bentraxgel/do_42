#include "../push_swap.h"
/*
void	four_sort(t_stack *stack, int idx)
{
	int	i;
	int pa;
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
		printf("stack->a[%lu] : %d\n", idx, stack->a[stack->a_len - 1]);
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
*/

// void	a_four_sort(t_stack *stack, t_info *info, int idx)
// {
// 	int	i;

// 	i = -1;
// 	info->pb = 0;
// 	info->ra = 0;
// 	a_stack_indexing(stack, stack->a_len - 4, 4);
// 	while (++i < 4)
// 	{
// 		printf("stack->a[%lu] : %d\n", stack->a_len - 1, stack->a[stack->a_len - 1]);
// 		if (stack->a[stack->a_len - 1] == 0 || stack->a[stack->a_len - 1] == 1)
// 			p_command(stack, info, STACK_B);
// 		else
// 			r_command(stack, info, STACK_A, stack->a_len - 1);
// 		printf("while\n");
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 		printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
// 		printf("pb : %d\t ra : %d\n", info->pb, info->ra);
// 	}
// 	printf("\n rr\n");
// 	while (info->ra-- > 0){
// 		rr_command(stack, STACK_A, stack->a_len - 1);
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 		printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
// 		printf("pb : %d\t ra : %d\n", info->pb, info->ra);
// 	}
// 	printf("\ntwo\n");
// 	two_sort(stack, STACK_A, stack->a_len -1);
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 		printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
// 		printf("pb : %d\t ra : %d\n", info->pb, info->ra);
// 	two_sort(stack, STACK_B, stack->b_len -1);
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 		printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
// 		printf("pb : %d\t ra : %d\n", info->pb, info->ra);
// 	while (info->pb-- > 0)
// 		p_command(stack, info, STACK_A);
// }

// void	b_four_sort(t_stack *stack, t_info *info, int idx)
// {
// 	int	i;

// 	i = -1;
// 	info->pa = 0;
// 	info->rb = 0;
// 	b_stack_indexing(stack, stack->b_len - 4, 4);
// 	for (int i = stack->b_len; i >= 0; i--)
// 		printf("b[%d] : %d\n", i, stack->b[i]);

// 	while (++i < 4)
// 	{
// 		if (stack->b[stack->b_len - 1] == 0 || stack->b[stack->b_len - 1] == 1)
// 			r_command(stack, info, STACK_B, stack->b_len - 1);
// 		else
// 			p_command(stack, info, STACK_A);
// 		printf("while\n");
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 		printf("a_len : %zu\t b_len : %zu\n", stack->a_len, stack->b_len);
// 		printf("pa : %d\t rb : %d\n", info->pa, info->rb);
// 	}
// 	printf("\ncommand\n");
// 	while (info->rb-- != 0)
// 		rr_command(stack, STACK_B, stack->b_len - 1);
// 	printf("\n");
// 	two_sort(stack, STACK_A, stack->a_len -1);
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 	two_sort(stack, STACK_B, stack->b_len -1);
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 			printf("\np_command\npa : %d\n", info->pa);
// 	while (info->pa-- != 0){
// 		p_command(stack, info, STACK_B);
// 		for (int i = idx; i >= 0; i--)
// 			printf("a[%d] : %d\tb[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
// 	}
// }

void	a_four(t_stack *stack, t_info *info)
{	int	i;

	i = -1;
	info->pb = 0;
	info->ra = 0;
	// a_stack_indexing(stack, stack->a_len - 4, 4);
	while (++i < 4)
	{
		if (stack->a[stack->a_len - 1] == 0 || stack->a[stack->a_len - 1] == 1)
			p_command(stack, info, STACK_B);
		else
			r_command(stack, info, STACK_A, stack->a_len - 1);
	}
	while (info->ra-- > 0)
		rr_command(stack, STACK_A, stack->a_len - 1);
	two_sort(stack, STACK_A);
	two_sort(stack, STACK_B);
		printf("pb : %d\t ra : %d\n", info->pb, info->ra);
	while (info->pb-- > 0)
		p_command(stack, info, STACK_A);
}

void	b_four(t_stack *stack, t_info *info)
{
	int	i;

	i = -1;
	info->pa = 0;
	info->rb = 0;
	// b_stack_indexing(stack, stack->b_len - 4, 4);
	while (++i < 4)
	{
		if (stack->b[stack->b_len - 1] == 0 || stack->b[stack->b_len - 1] == 1)
			r_command(stack, info, STACK_B, stack->b_len - 1);
		else
			p_command(stack, info, STACK_A);
	}
	while (info->rb-- != 0)
		rr_command(stack, STACK_B, stack->b_len - 1);
	two_sort(stack, STACK_A);
	two_sort(stack, STACK_B);
	while (info->pa-- != 0)
		p_command(stack, info, STACK_B);
}

int	main()
{
	t_stack stack;
	t_info	info;
	int		num = 4;

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
	for (int i = 0; i < num; i++)
	{
		if (i % 2)
			stack.b[i] = 20 + i;
		else
			stack.b[i] = 5 + i;
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
	a_four(&stack, &info);
	b_four(&stack, &info);
	printf("a_sort\n\n");
	for (int i = num; i >= 0; i--)
		printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
	return (0);
}