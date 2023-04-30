#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	leaks()
{
	system("leaks -q a.out");
}

void	test(char *arr)
{
	int *num;
	num[0] = 1;
	num[1] = 2;
	num[2] = 3;
}

int	my_atoi(char *str, int i)
{
	// if (i == 2)
	// 	exit(1);
	return (ft_atoi(str));
}

int	main()
{
	atexit(leaks);
	char **arr;
	char *s = "123";
	char *sa = "-456one";
	arr = malloc(sizeof(char *) * 100);
	arr[0] = malloc(ft_strlen(s) + 1);
	ft_strlcpy(arr[0], &s[0], ft_strlen(s) + 1);
	arr[1] = malloc(ft_strlen(s) + 1);
	ft_strlcpy(arr[1], &sa[0], ft_strlen(sa) + 1);
	arr[2] = malloc(ft_strlen(s) + 1);
	ft_strlcpy(arr[2], &sa[0], ft_strlen(sa) + 1);
	
	int i = 0;
	int	*num;

	while (arr[i]) //단어 개수세기
		i++;
	num = malloc(sizeof(int *) * i);
	i = 0;
	while (arr[i])
	{
		num[i] = my_atoi(arr[i], i);
		printf("num[%d] : %d\n", i, num[i]);
		i++;
		
	}
	for (int i = 0; num[i]; i++)
		printf("num[%d] : %d\n", i, num[i]);
	// for (int i = 0; arr[i]; i++)
	// {
	// 	printf("%s\n", arr[i]);
	// 	printf("i : %d\n", i);
	// }

	for (int i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	free(num);
	// int *num;
	// num = malloc()
	// for (int i = 0; arr[i]; i++)
	// {
	// 	test(arr[i]);

	// }
	return (0);
}