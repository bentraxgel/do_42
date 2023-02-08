#include <stdio.h>
#include <stdlib.h>

void	change(char *a)
{
	a++;
}

void	change2(char **a)
{
	(*a)++;
}

int main()
{
	char *a;
	a = malloc(5);
	for (int i = 0; i < 5; i++)
		a[i] = 'a';
	change(a);
	printf("%s\n", a);
	change2(&a);
	printf("%s\n", a);
}
