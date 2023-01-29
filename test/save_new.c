#include "header.h"

size_t	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
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
	dest = adr;
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		idx;

	idx = 0;
	while (s1[idx])
	{
		idx++;
	}
	ret = (char *)malloc(sizeof(char) * (idx + 1));
	if (!ret)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		ret[idx] = s1[idx];
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sstart;
	size_t	i;
	size_t	s_len;

	i = 0;
	sstart = (size_t)start;
	s_len = ft_strlen(s);
	if (s_len <= sstart)
		return (ft_strdup(""));
	if (s_len - start <= len)
		str = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (s_len - start > len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[sstart + i] && i < len)
	{
		str[i] = s[sstart + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*my_new_save(char *save, int idx) //save = new((save - ret)) -> check!
{
	char	*ret;
	int	count;

	count = 0;
	
	while (save[idx + count])
		count++;
	if (count)
	{
		save = ft_substr(save, idx, count);
	//	free(save);
	//	save = 0;
		return (save);
	}
	return (0);
}

char	*my_new_ret(char *save, int find)
{
	char	*ret;

	ret = malloc(find + 2);
	ft_memcpy(ret, save, find + 1);
	ret[find + 1] = 0;
	printf("in fuc ret : %s\nret_ADR : %p\n", ret, ret);
	printf("in fuc ret : %s\nret_ADR : %p\n", ret, &ret);
	free(ret);
	printf("ret_ADR : %p\n", ret);
	printf("ret_ADR : %p\n", &ret);
	return (ret);
}

void	leaks()
{
	system("leaks a.out");
}

int	main()
{
	atexit(leaks);
	static char *save;
	char		*ret;
	int			idx = 2;

	save = "se\nok";
	printf("before : %s\n", save);
	printf("---------------\n");
	ret = my_new_ret(save, idx);
	save = my_new_save(save, idx + 1);
	printf("after : %s\n", save);
	printf("---------------\n");
	printf("ret : %s\n", ret);
}