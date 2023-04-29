#include <stdlib.h>

typedef struct tagnode
{
	int data;
	struct tagnode prev;
	struct tagnode next;
}node;

node	*create_node(int newdata)
{
	node	*newnode;

	newnode = malloc(sizeof(node));
	newnode->data = newdata;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

void	destroy_node(node *node)
{
	free(node);
}

void	appendnode(node **head, node*newnode)
{
	node *tail;

	if (*head == NULL)
		*head = newnode;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		newnode->prev = tail;
		tail->next = newnode;
	}
}

//노드 탐색 연산 location이 주어진다는 가정
node	*getnodeat(node *head, int location)
{
	node *current = head;

	while (current != NULL && (--location) >= 0)
		current = current->next;
	return (current);
}

void	remove_node(node **head, node *remove)
{
	node *tmp;

	if (*head == remove)
	{
		*head = (*head)->next;
		if ((*head)->next == NULL)
			(*head)->prev = NULL;
		remove->prev = NULL;
		remove->next = NULL;
	}
	else
	{
		tmp = remove;
		if (remove->next != NULL)
			remove->prev->next = tmp->next;
		if (remove->prev != NULL)
			remove->next->prev = tmp->prev;
		remove->prev = NULL;
		remove->next = NULL;
	}
}

void	insertafter(node *current, node* new)
{
	
	new->next = current->next;
	new->prev = current;
	if (current->next != NULL)
	{
		current->next->prev = new;
		current->next = new; //왜 이게 if문 안에 들어가는지 모르겠어
		//if문 밖에 있어야하지 않아? current->next ==NULL이어도 current->next에 new를 두는거잖아
	}
}

int get_node_count(node *head)
{
	unsigned int	count;
	node *current;

	current = head;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}