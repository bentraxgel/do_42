#include <stdio.h>

int	main()
{
	int	i = -1;
	char *str = "hel%lo";
	while (*(str + i++) != '\0')
	{
		if (*(str + i) == '%')
			printf ("\n");
		printf("%c ", *(str + i));
	}
	printf("\nEND");
}