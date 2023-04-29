#include <stdlib.h>

typedef struct tagnode
{
	char	*data;
	struct tagnode *next;
} node;

typedef struct s_linkedqueue
{
	node* front;
	node* rear;
	int count;
}linkedqueue;

void	create_queue(linkedqueue **queue)
{
	*queue = malloc(sizeof(linkedqueue));
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->count = 0;
}

void	destroy_node(node *node)
{
	free(node->data);
	free(node);
}

int	ISempty(node *queue)
{
	return (queue->front == NULL);
}

void	destroy_queue(linkedqueue *queue)
{
	node *poped;

	while (!ISmepty(queue))
	{
		poped = dequeue(queue);
		destroy_node(poped);
	}
	free(queue);
}

void	enqueue(linkedqueue *queue, node *new)
{
	if (queue->front == NULL)
	{
		queue->front = new;
		queue->rear = new;
		queue->count++;
	}
	else
	{
		queue->rear->next = new;
		queue->rear = new;
		queue->count++;
	}
}

node	*dequeue(linkedqueue *queue)
{
	node *front;

	front = queue->front;
	if (queue->front->next == NULL)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
		queue->front = queue->front->next;
	queue->count--;
	return (front);
}
