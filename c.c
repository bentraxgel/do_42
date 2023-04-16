#include <stdio.h>

void	func(char ch)
{
	printf("ch : %c\n", ch);
	if (ch == 'd')
		printf("\n\tIn if\n");
	printf("\n\tIN func\n");
		// return (2);
	// else ()
	// return (1);

}

int	main()
{
	char *p = "abcd";
	int	n = -1;
	
	while (p[++n])
	{
		printf("front : %d\t%c\n", n, p[n]);
		if (p[n] == 'c')
			func(p[n + 1]);
		printf("back : %d\n", n);
	}

	// printf("%d", func('s'));
}