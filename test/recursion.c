#include "header.h"

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
	ret[s1_len + s2_len] = 0;
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
		return (0);
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

char	*my_save_buf(int fd)
{
	char		buf[3];
	char		*ret;
	static char	*save;
	int			check;
	int			find;

	ret = 0;
	find = 0;
	check = read(fd, buf, 3);
	if (check == 0 && save != 0)
		return (save);
	save = ft_strjoin(save, buf);
	while (save[find])
	{
		if (save[find] == '\n')
		{
			ret = ft_substr(save, 0, find + 1);
			save = ft_substr(save, find + 1, ft_strlen(save) - (find + 1));
			return (ret);
		}
		find++;
	}
	if (ret == 0)
		my_save_buf(fd);
	return (ret);
}

void	*ft_memset(void *str, int value, size_t len)
{
	while (len--)
		*(unsigned char *)(str + len) = (unsigned char)value;
	return (str);
}

char	*test_ret(int fd)
{
	static char *save;
	char		buf[BUFFER_SIZE + 1];
	char		*ret;
	int			check;
	int			find;

	ret = 0;
	find = 0;
	while (ret == 0)
	{
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		check = read(fd, buf, BUFFER_SIZE);
		if (check == 0 && save != 0)
			return (save);
 		save = ft_strjoin(save, buf);
		while (save[find])
		{
			if (save[find] == '\n')
			{
				ret = ft_substr(save, 0, find + 1);
				save = ft_substr(save, find + 1, ft_strlen(save) - (find + 1));
				return (ret);
			}
			find++;
		}
	}
	return (ret);
}

#include <errno.h>
extern int errno;
		if (errno != 0)
			printf("errno: %s\n", strerror(errno));

char	*test_ret1(t_list *lst)
{
	char		*ret;
	int			check;
	int			find;

	ret = 0;
	find = -1;
	while (ret == 0)
	{
		ft_memset(lst->buf, 0, BUFFER_SIZE + 1);
		check = read(lst->fd, lst->buf, BUFFER_SIZE);
		if (check == 0 && lst->save != 0)
			return (lst->save);
		lst->save = ft_strjoin(lst->save, lst->buf);
		while (lst->save[++find])
		{
			if (lst->save[find] == '\n') 
			{
				ret = ft_substr(lst->save, 0, find + 1);
				lst->save = ft_substr(lst->save, find + 1,\
							ft_strlen(lst->save) - (find + 1));
				return (ret);
			}
		}
	}
	return (ret);
}

int	main()
{
	static t_list	*lst;
	lst = malloc(sizeof(t_list));
	lst->next = 0;

	lst->fd = open("text.txt", O_RDONLY);

	//char	*save = 0;
	// int	fd = open("text.txt", O_RDONLY);
	for (int i = 0; i < 7; i++)
	{
		// printf("%d번째 : %s\n", i, my_save_buf(fd));
		// printf("%d번째 : %s\n", i, test_ret(fd));
		// printf("%d번째 : %s\n", i, test_ret(lst->fd, lst->save));
		printf("%d번째 : %s\n", i, test_ret1(lst));
	}
	printf("END");

}