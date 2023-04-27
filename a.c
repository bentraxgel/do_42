#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/*
void	func(int argc, char **argv)
{
	printf("argc : %d\n", argc);
	printf("argv : %s\n", *argv);
	printf("argv : %s\n", *(argv + 1));
	printf("argv : %s\n", *(argv + 2));
	printf("argv : %s\n", *(argv + 3));
	printf("argv : %s\n", *(argv + 4));
	for (int i = 0; i < argc; i++)
	{

		printf("while(%d) : ");
	}
	
	// printf("argv : %s\n", *(argv + 5));
	// printf("argv : %s\n", *(argv + 6));
	// printf("argv : %s\n", *(argv + 7));
	// printf("argv : %s\n", *(argv + 8));
	// printf("argv : %s\n", *(argv + 9));
	// printf("argv : %s\n", *(argv + 10));
}
*/

int	ft_isspace(int c)
{
	return (c == 32 || (8 < c && c < 14));
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result * sign);
}

char	*ft_substr(char **s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sstart;
	size_t	i;
	size_t	s_len;

	i = 0;
	sstart = (size_t)start;
	s_len = strlen(*s);
	if (s_len - start <= len)
		str = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (s_len - start > len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[sstart + i] && i < len)
	{
		str[i] = *s[sstart + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	main(int argc, char *argv[])
{
	write(1, "no.1\n", 5);
	write(2, "no.2\n", 5);
	printf("%d\n\n", argc);
	int	i = 1;
	int start = 1;
	char	*tmp;
	while (argv[i])
	{
		for(int j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] == ' ')
			{
				tmp = ft_substr(argv, start, i - start);
				for (int i = 0; tmp[i]; i++)
				{
					printf("sub_ : %c\n", tmp[i]);
				}
				printf("sub_ : %s\n", tmp);
				start = i;
			}
				// printf("argv[%d][%d] : %c\n", i, j, argv[i][j]);
		}
		printf("\tstr_argv[%d] : %s\n", i, argv[i]);
		i++;
	}
	// func(argc, argv);
}
