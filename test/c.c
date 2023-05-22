#include <stdlib.h>
#include <stdio.h>
 //leak이..num을 어찌해야하누..
void func(char *av, int *num) //atoi하면서 오류 찾고 exit
{
	printf("num add %p\n", num);
	// printf("FUNC\n");
	for(int i = 0; av[i]; i++)
	{
		printf("func *Av : %c %d\n", av[i], av[i]);
		if (av[i] == '9')
		{
			printf("ERROR\n");
			exit(1);
		}
		num = malloc(sizeof(int) * i);
		num[i] = av[i] - '0';
		printf("num : %d\n", num[i]);
	}
	// free(num);
	// return (num);
}

void move(char **av, int *num)
{
	int	i = 1;
	int j = 0;
	// int	*num;

	printf("move num add %p\n", num);
	// for(int i = 0; av[i]; i++)
	// 	printf("move av : %s\n", av[i]);

	while (av[i])
	{
		printf("\ti %d\n", i);
		func(av[i], num);
		// num[j++] = func(av[i], num);
		i++;
	}
	// return (num);
}

void leak()
{
	system("leaks -q a.out");
}

int	main(int ac, char *av[])
{
	atexit(leak);
	int *num;

	// num = move(av);
	move(av, num);
	printf("main num %p\n", num);
	for (int i = 0; num[i] && i < 5; i++)
		printf("num[%d] : %d\n", i, num[i]);
	
}