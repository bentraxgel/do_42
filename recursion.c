#include <stdio.h>
#include "printf.h"

void	make_str(int n, char **str)
{
	char ch;
	char	*tmp;

	tmp = *str;
	// *str = malloc(ft_strlen(*str) + 1);
	if (0 <= n && n <= 9)
	{
		ch = n + '0';
		printf("s : %s\n", *str);
		printf("p : %p\n", *str);
		*str = ft_strjoin_free(*str, &ch);
	}
	else if (n == 10)
		*str = ft_strjoin_free(*str, "A");
	else if (n == 11)
		*str = ft_strjoin_free(*str, "B");
	else if (n == 12)
		*str = ft_strjoin_free(*str, "C");
	else if (n == 13)
		*str = ft_strjoin_free(*str, "D");
	else if (n == 14)
		*str = ft_strjoin_free(*str, "E");
	else if (n == 15)
		*str = ft_strjoin_free(tmp, "F");
	printf("make : %s\n", *str);
}

void	go(int n, char *str)
{
	// char *str;

	// str = 0;
	if (n == 0)
		return ;
	go(n / 10, str);
	make_str(n % 10, &str);
	printf("%d\n", n % 10);
}

int	main()
{
	char	*str;
	// printf("%d\n", 3408 / 10);
	// printf("%d\n", 3408 % 10);
	str = 0;
			printf("mainp : %p\n", str);

	// go(127, str);
	make_str(1, &str);
	make_str(2, &str);
	// printf("hex : %s\n", str);
}