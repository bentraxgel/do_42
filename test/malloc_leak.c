#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	leak()
{
	system("leaks a.out");
}

char	*func()
{
	char	*str;
	str = malloc(3);
	str[0] = 'H';
	str[1] = 'I';
	str[2] = '\0';
	return (str);
}

int	my_va_int(char ch, long long num)
{
	int		len;
	char	*str;

	len = 0;
	if (ch == 'c')
		str = func();
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	free(str);
	return (len);
}

int	main()
{
	atexit(leak);
	int	len = my_va_int('c', 10);
	printf("\nlen : %d", len);
}