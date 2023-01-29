#include <stdio.h>
#include <stdlib.h>

void	one_func()
{
	printf("error\n");
	exit(1);
}

void	other_func()
{
	printf("right\n");
}

void	leack_check()
{
	system("leaks a.out");
}

int main(void)
{
	int	i;
	atexit(leack_check);
	scanf("%d", &i);
	if (i == 1)
		one_func();
	else
		other_func();
	return (0);
}