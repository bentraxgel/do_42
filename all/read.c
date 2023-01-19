/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_read_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:01:08 by seok              #+#    #+#             */
/*   Updated: 2023/01/16 23:23:15 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -D BUFFER_SIZE=3 gnl_read_test.c get_next_line_utils.c get_next_line.h
#include <fcntl.h>
#include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
# define BUFFER_SIZE 3
//#include "get_next_line.h"

/**/
void	*ft_memset(void *str, int value, size_t len)
{
	while (len--)
		*(unsigned char *)(str + len) = (unsigned char)value;
	return (str);
}
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
/**/

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*save;
	int		check;
	int		i;

	i = 0;
	ft_memset(buf, 0, BUFFER_SIZE);
	save = malloc(BUFFER_SIZE);
	//check = read(fd, buf, BUFFER_SIZE);
	printf("check : %d\n", check);
	printf("check : %p\n", &check);
	int	*num = &check;
	for (int i = 0; i < 100; i++)
	{
		printf("ADR : %p %d\n", num, *num);
		num += i;		
	}
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check > 0)
		{
			save = ft_strjoin(save, buf);
			ft_memset(buf, 0, BUFFER_SIZE);
		}
		else if (check == 0)
		{
			printf("EOF\n");
			break ;
		}
		printf("[%d] : %s\n", i++, save);
	}
	return (0);
}

int	main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
}
