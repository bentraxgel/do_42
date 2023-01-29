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
	system("gcc a.c -o tina");
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
	if (system("gcc a.c -o tina"))
	{
		printf("DO!\n");
	}
	return (0);
}