/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:58:22 by junlee2           #+#    #+#             */
/*   Updated: 2023/02/13 02:47:06 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 10

typedef struct s_fdlist
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	ssize_t			totallen;
	ssize_t			stack;
	ssize_t			s_idx;
	ssize_t			c_idx;
	ssize_t			status;
	ssize_t			indent;
	struct s_fdlist	*next;
	struct s_fdlist	*prev;
}	t_fdlist;

char		*get_next_line(int fd);
t_fdlist	*find_fd(int fd, t_fdlist *fdlist);
char		*get_line_re(t_fdlist	*fdlist);
char		*free_fdlist(t_fdlist *fdlist);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
