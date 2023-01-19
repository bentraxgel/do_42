#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dstsize != 0)
	{
		while (src[idx] && idx < dstsize - 1)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = 0;
	}
	return (3);
}

char	*func(char *str)
{
	char	*ret;
	// static char	*save;

	ret = malloc(6);
	ft_strlcpy(ret, str+2, 5);
	// save = malloc(6);

	// ft_strlcpy(save, str+2, 5);
	// free(save);
	// printf("save : %s\n", save);
	return (ret);
}

void	leaks()
{
	system("leaks a.out");
}

int	main()
{
	atexit(leaks);
	char *save = "abcdefgh";
	printf("ret : %s\n", func(save));
	return (0);
}