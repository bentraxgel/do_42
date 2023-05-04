#include <stdlib.h>

typedef struct tagnode
{
	char *data;
	struct tagnode* next;
}node;

typedef struct taglinkedliststack
{
	node *list; //head
	node *top; //tail
}lststack;

int	ISempty(lststack *stack)
{
	return (stack->list == NULL); //참이면 1 거짓이면 0 반환
}

void	create_stack(lststack **stack)
{
	*stack = malloc(sizeof(lststack));
	(*stack)->list = NULL;
	(*stack)->top = NULL;
}

void	destroy_stack(lststack **stack)
{
	node *poped;

	while (ISempty(stack))
	{
		poped = pop(stack);
		destroy_node(poped);
	}
	free(stack);
}

node*	create_node(char *data)
{
	node *new;

	new = malloc(sizeof(lststack));
	new->data = malloc(strlen(data) + 1);
	strcpy(new->data, data);
	new->next = NULL;

	return (new);
}

void	destroy_node(node *node)
{
	free(node->data);
	free(node);
}

void	push(lststack *stack, node *new)
{
	if (stack->list == NULL)
		stack->list = new;
	else
		stack->top->next = new;
	stack->top = new;
}

node	*pop(lststack *stack)
{
	node	*topnode;
	node	*tmp;

	topnode = stack->top; //반환할 (pop할)node 주소 저장

	if (stack->list == stack->top)
	{
		stack->list = NULL;
		stack->top = NULL;
	}
	else
	{
		//이부분은 양방향리스트로 하면 탐색없이 pre를 찾아서 바로 바꿀 수 있다.
		tmp = stack->list;
		while (tmp != NULL && tmp->next != stack->top)
			tmp = tmp->next;
		stack->top = tmp;
		stack->top->next = NULL;
	}
	return (topnode);
}


