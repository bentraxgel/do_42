#include <stdio.h>

typedef int Elementtype;

typedef struct s_node
{
	Elementtype Data;
	struct s_node *next;
} node;

int	main()
{
	node *arr;
	node te;
	printf("%ld %ld\n", sizeof(te), sizeof(arr));
}