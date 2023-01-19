#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	if (s == 0)
		return (0);
	while (s[idx])
		idx++;
	return ((size_t) idx);
}

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
	*(char *)dest++ = 't';
	*(char *)dest++ = 't';
	*(char *)dest = 't';
	dest = adr;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len);
	//ret[s1_len + s2_len] = 0;
	return (ret);
}

void	leaks()
{
	system("leaks a.out");
}

char *func()
{
	//atexit(leaks);
	char	*s1 = "helloabc\n"; //9
	char	*s2 = "world\n"; //6
	static char	*save;
	char	*ret;
	printf("save : %p\nret : %p\n", save, ret);
	ret = save;
	save = 	ft_strjoin(save, s2);
	printf("save : %p\nret : %p\n", save, ret);
	printf("save : %s\n", save);
	ret = save;
	printf("ret : %s\n", ret);
	save = 	ft_strjoin(save, s1);
	printf("save : %p\nret : %p\n", save, ret);
	free(ret);
	printf("save : %p\nret : %p\n", save, ret);
	printf("ret : %s\n", ret);
	// ret = malloc(3);
	char	*no = 0;
	strlcpy(ret, no, 15);
	 printf("ret2 : %s : \t%p\n", ret, ret);
	printf("save2 : %s : \t%p\n", save, save);
	// free(ret);
	// // //ret = 0;
	return (ret);
}
char	*save()
{
	static char	*save;
	char		*ret;
	ret = save;
	save = ft_strjoin(save, "abc");
	free(ret);
	ret = save;
	save = ft_strjoin(save, "efg");
	free(ret);
	//ret = ft_strlcpy
	printf("ret : %s\n", ret);
	printf("save : %s\n", save);
	return (ret);
}

int	main()
{
	//atexit(leaks);
	// printf("\nmain : %s\n", func());
	// printf("----------------------------\n");
	// printf("\nmain : %s\n", func());
	printf("\tEND : %s\n", save());

}
