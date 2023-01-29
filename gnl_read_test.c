/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_read_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:01:08 by seok              #+#    #+#             */
/*   Updated: 2023/01/28 19:05:13 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -D BUFFER_SIZE=3 gnl_read_test.c gnl_utils.c get_next_line.h

#include "get_next_line.h"

/*
#include <fcntl.h>
#include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
# define BUFFER_SIZE 3
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
*/
char	*my_find_char(char *save, int check)
{
	printf("saveADR : %p\n", save);
	int	idx;
	int			find;
	char		*ret;
	idx = 0;
	find = idx;
	ret = 0;
	//printf("save : %s\n", save);
	// printf("==find in==\nsave : %s\n", save);
	// printf("save[idx] : %c\n", save[idx + 1]);
	// while (save[find])
	// {
	// printf("\tsave[%d] : %c\n", find, save[find]);
	// 	if (save[find] == '\n')
	// 	{
	// 		ret = ft_substr(save, idx, find - idx + 1);
	// 		printf("@@@find(\\n)[%d] ret : %s\n", find, ret);
	// 		idx = find + 1;
	// 		return (ret);
	// 	}
	// 	find++;
	// }
	if (check == 0)
		ret = ft_substr(save, idx, find - idx);
	return (ret);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	static char	*save;
	int		check;
	int		i;
	char	*ret;

	i = 0;
	ft_memset(buf, 0, BUFFER_SIZE);
	//save = malloc(BUFFER_SIZE);
	printf("\tfir_ARD(save) : %p\n", save);
	check = 0;
	int	o = 1;
	while (check >= 0)
	{
		printf("=======while_check %d=====\n", o++);
		check = read(fd, buf, BUFFER_SIZE);
		save = ft_strjoin(save, buf);
		printf("\tARD : %p\n", save);
		printf("\t&ARD : %p\n", &save);
		ret = my_find_char(save, check);
		free(save); printf("!!free!!\n");
		if (ret)
			break ;
		ft_memset(buf, 0, BUFFER_SIZE);
	}
	return (ret);
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