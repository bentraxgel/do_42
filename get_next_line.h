/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:45:51 by seok              #+#    #+#             */
/*   Updated: 2023/01/29 09:08:39 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*	test	*/
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	static char		*save;//아놔 왜  안돼
	struct s_list	*pre; //free할거 아아니니면  없없애애기
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
char	*my_find_char(char *save, int check);
void	*ft_memset(void *str, int value, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
#endif