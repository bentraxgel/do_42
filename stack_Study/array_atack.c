#include <stdio.h>

typedef int	elementtype;
typedef struct tagnode
{
	elementtype data;
}node;

typedef struct tagarraystack
{
	int capacity; //총 용량
	int top; //최상위 노드 위치
	node *nodes; // 노드 배열
}arraystack;

void	AS_createstack(arraystack **stack, int capacity)
{
	*stack = (arraystack *)malloc(sizeof(arraystack));
	(*stack)->nodes = (node *)malloc(sizeof(node) * capacity);
	(*stack)->capacity = capacity;
	(*stack)->top = -1;
}

void	AS_push(arraystack* stack, elementtype data)
{
	stack->top++;
	stack->nodes[stack->top].data = data; //stack에 있는 포인터로 선언한 nodes를 배열로 생각한것.
}

int	main()
{
	arraystack *stack;
	AS_createstack(&stack, 3);
	// printf("stack  %s\t%s\n",*stack, stack);
	printf("*stack %p %p\t\n", *stack, stack);

}