#include "header.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*adr;

	adr = dest;
	if (dest == src)
		return (dest);
	while (len--)
	{
		*(char *)dest++ = *(char *)src++;
	}
	dest = adr;
	return (dest);
}

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
	return (ft_strlen(src));
}

void	print(char *str)
{
	for (int i = 0; i < 7; i++)
	{
		printf("%c", str[i]);
	}
}

int	main()
{
	char	*dst = "hello";
	char	*src = 0;
	char	*mret;

	printf("memcpy : ");
	mret = ft_memcpy(dst, src, 6);
	printf("memcpy : %s\n", mret);
	print(mret);
	printf("\n\nstrlcpy : ");
	char	*ret = ft_strlcpy;
	printf("\n");
}