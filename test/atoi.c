#include <stdio.h>

void	func(char *str)
{
		while (*str)
		printf("%c", *(str++));

}

int	main()
{
	char *str = "hello";

	for(int i = 0; str[i]; i++)
		printf("%c", str[i]);
	printf("\n");
	func(str);
	while (*str)
		printf("%c", *(str++));
}