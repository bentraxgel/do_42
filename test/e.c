#include <stdio.h>
#include <stdlib.h>

typedef struct s_group
{
	int *a;
	int	*b;
} t_group;

void	func1(int *arr)
{
	arr[0] = 500;
}

void	func(t_group *group)
{
	printf("func\n");
	func1((group->a));
}

int	main()
{
	t_group group;

	group.a = malloc(sizeof(int) * 2);
	group.b = malloc(sizeof(int) * 2);

	group.a[0] = 100;
	group.a[1] = 200;
	group.b[0] = 10;
	group.b[1] = 20;
	printf("a[0] : %d\na[1] : %d\n", group.a[0], group.a[1]);
	func(&group);
	printf("a[0] : %d\na[1] : %d\n", group.a[0], group.a[1]);
}