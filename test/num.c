#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	*str = "se\nw";
	char	*str1 = "se\nw";
	char	*new;
	new = str1;
	printf("new : %s\n", new);

	int	j = 0;
	while (str[j])
		j++;
	printf("strlen2 : j_%d\n", j);

	int	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	printf("strlen : i_%d\n", i);
printf("-----------\n");
	str1 = (char *)malloc(sizeof(char) * (3 + 2));
	str1 = "12345679sldkjf";
	new = str1;
	printf("str1ARD : %p\nnewARD : %p\n\n", str1, new);
	printf("new1 : %s\n", new);
	printf("+0 : %c\n", *(str1 + 0));	
	//*(str1 + j) = '1';
	printf("+1 : %c\n", *(str1 + 3));

	//*(str1 + j+1) = '2';
	printf("+2 : %c\n", *(str1 + 4));
	printf("all : %s\n", new);
}
