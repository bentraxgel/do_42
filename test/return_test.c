#include <stdio.h>
#include <stdlib.h>

char	*func(char **str)
{
	*str = "you";
	printf("func : ");
	return ("qq");
}

int	main()
{
	char	*str = "test";
	char	*ret;
	
	ret = malloc(5);
	if ((ret = func(&str)))
		printf("in\n");
	printf("ret : %s\n", ret);
	printf("str : %s\n", str);
	return (0);
}