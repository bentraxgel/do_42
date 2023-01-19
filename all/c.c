#include <stdio.h>

static int num = 0;

void	test_print(char *str)
{
	printf("test_print() : %s\n", str);
}

int	add(int on)
{
	num += 10;
	on++;
	printf("add : %d", num);
	return (on);
}

int	test()
{
	char	*str;
	int		on;

	on = 60;
	str = "test";
	return (test_print(str), num = add(on), 2);
}

int	main()
{
	char	*str = "test";
	int	to = test();
	printf("\n\nnum = %d\n", num);
	return (to);
}