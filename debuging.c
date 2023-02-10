#include "get_next_line.h"

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

void	*ft_memset(void *str, int value, size_t len)
{
	while (len--)
		*(unsigned char *)(str + len) = (unsigned char)value;
	return (str);
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

t_list	*my_lst_find(t_list **lst, int f_fd)
{
	t_list	*temp;

	temp = (*lst);
	if (*lst == 0)
	{
		temp = malloc(sizeof(t_list));
		temp->fd = f_fd;
		temp->next = NULL;
		*lst = temp;
		return (temp);
	}
	while (temp)
	{
		if (temp->fd == f_fd)
			return (temp);
		temp = temp->next;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	temp = malloc(sizeof(t_list));
	(*lst)->next = temp;
	temp->next = NULL;
	temp->fd = f_fd;
	return (temp);
}

void	my_lst_free(t_list *find, t_list **lst)
{
	while((*lst)->next == find)
		*lst = (*lst)->next;
	find->fd = 0;
	(*lst)->next = find->next;
	find->next = NULL;
	free(find);
}

char	*my_save_buf(t_list *find, t_list *lst)
{
	char		*ret;
	int			check;
	int			idx;

	ret = 0;
	//idx = -1;
	while (ret == 0)
	{
		ft_memset(find->buf, 0, BUFFER_SIZE + 1);
		check = read(find->fd, find->buf, BUFFER_SIZE);
		if (check == 0 && find->save != 0)
		{
			ret = ft_substr(find->save, 0, ft_strlen(find->save));
			my_lst_free(find, &lst);
		}
		else if (check == 0 && find->save == 0)
			my_lst_free(find, &lst);
		else
		{
			find->save = ft_strjoin(find->save, find->buf);
			idx = -1;
			while (find->save[++idx])
			{
				if (find->save[idx] == '\n')
				{
					ret = ft_substr(find->save, 0, idx + 1);
					find->save = ft_substr(find->save, idx + 1,\
								ft_strlen(find->save) - (idx + 1));
					return (ret);
				}
			}
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*find;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	find = my_lst_find(&lst, fd);
	return (my_save_buf(find, lst));
}
int	main()
{
	int	fd;
	char *ret;

	//ret = 0;
	fd = open("text.txt", O_RDONLY);
	printf("===main_print===\n");
	ret = get_next_line(fd);
	printf("1 ret : %s\n", ret);
	printf("---------------------------------------\n");
	ret = get_next_line(fd);
	printf("2 ret : %s\n", ret);
	printf("---------------------------------------\n");
	ret = get_next_line(fd);
	printf("3 ret : %s\n", ret);
	printf("---------------------------------------\n");
	ret = get_next_line(fd);
	printf("4 ret : %s\n", ret);
}