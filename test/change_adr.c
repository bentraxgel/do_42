#include <stdio.h>

void	test(char **ptr)
{
	printf("-----------------\n");
	printf("*test() : %p\n", *ptr);
	printf("test() : %p\n", ptr);
	printf("&test() : %p\n", &ptr);
	*ptr = "abc";
	printf("\t---------\n");
	printf("*abc_test() : %p\n", *ptr);
	printf("abc_test() : %p\n", ptr);
	printf("abc_&test() : %p\n", &ptr);
}

int	main()
{
	char	*str;

	str = "ABC";
	printf("before : %s\n", str);
	printf("strADR : %p\n", str);
	printf("&strADR : %p\n", &str);
	test(&str);
	printf("after : %s\n", str);
	return (0);
}