/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:45:51 by seok              #+#    #+#             */
/*   Updated: 2023/01/15 16:35:44 by seok             ###   ########.fr       */
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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *str, int value, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif