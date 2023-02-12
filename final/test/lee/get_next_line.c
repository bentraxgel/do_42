/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:51:24 by junlee2           #+#    #+#             */
/*   Updated: 2023/02/13 02:57:03 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:58:24 by junlee2           #+#    #+#             */
/*   Updated: 2023/02/13 02:46:46 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdlist	*find_fd(int fd, t_fdlist *fdlist)
{
	t_fdlist	*fdnode;

	fdnode = fdlist;
	while (fdnode->next != 0)
	{
		if (fdnode->next->fd == fd)
			return (fdnode->next);
		fdnode = fdnode->next;
	}
	fdnode->next = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (!fdnode->next)
		return (0);
	fdnode->next->fd = fd;
	fdnode->next->s_idx = -1;
	fdnode->next->next = 0;
	fdnode->next->prev = fdnode;
	return (fdnode->next);
}

char	*free_fdlist(t_fdlist *fdlist)
{
	fdlist->prev->next = fdlist->next;
	if (fdlist->next)
		fdlist->next->prev = fdlist->prev;
	free(fdlist);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	return_buffer(t_fdlist buff, char *returnstr, ssize_t max_idx)
{
	ssize_t	idx;
	ssize_t	bsize;

	if (!returnstr)
		return ;
	bsize = BUFFER_SIZE;
	idx = buff.s_idx;
	while (idx < max_idx)
	{
		returnstr[buff.stack * bsize + idx - buff.indent] = buff.buffer[idx];
		idx++;
	}
}

char	*readnext(t_fdlist	*fdlist)
{
	fdlist->s_idx = 0;
	fdlist->c_idx = 0;
	fdlist->status = read(fdlist->fd, fdlist->buffer, BUFFER_SIZE);
	if (fdlist->status == -1)
		return (0);
	fdlist->stack++;
	return (get_line_re(fdlist));
}

char	*get_line_re(t_fdlist	*fdlist)
{
	char		*returnstr;
	t_fdlist	buff;

	if (fdlist->status == 0)
	{
		if (fdlist->totallen == 0)
			return (0);
		return ((char *)malloc(fdlist->totallen + 1));
	}
	ft_memcpy(&buff, fdlist, sizeof(t_fdlist));
	while (buff.c_idx < buff.status)
	{
		fdlist->totallen++;
		if (buff.buffer[buff.c_idx] == '\n')
		{
			returnstr = (char *)malloc(fdlist->totallen + 1);
			return_buffer(buff, returnstr, buff.c_idx + 1);
			fdlist->s_idx = buff.c_idx + 1;
			return (returnstr);
		}
		buff.c_idx++;
	}
	returnstr = readnext(fdlist);
	return_buffer(buff, returnstr, buff.c_idx);
	return (returnstr);
}

char	*line_manager(t_fdlist	*fdlist)
{
	char	*returnstr;
	ssize_t	totallen;

	fdlist->totallen = 0;
	if (fdlist->s_idx == -1)
	{
		fdlist->status = read(fdlist->fd, fdlist->buffer, BUFFER_SIZE);
		if (fdlist->status <= 0)
			return (free_fdlist(fdlist));
		fdlist->s_idx = 0;
	}
	fdlist->indent = fdlist->s_idx;
	fdlist->c_idx = fdlist->s_idx;
	fdlist->stack = 0;
	returnstr = get_line_re(fdlist);
	if (returnstr == 0)
		return (free_fdlist(fdlist));
	totallen = fdlist->totallen;
	if (fdlist->status == 0)
		free_fdlist(fdlist);
	returnstr[totallen] = 0;
	return (returnstr);
}

char	*get_next_line(int fd)
{
	static t_fdlist	fdhead;
	t_fdlist		*workbench;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fdhead.fd = -1;
	workbench = find_fd(fd, &fdhead);
	if (!workbench)
		return (0);
	return (line_manager(workbench));
}
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		idx;
	int		fd;
	char	*str;

	//atexit(leak_check);
	idx = 1;
	fd = open("text.txt", O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s\n", idx, str);
		idx++;
		if (!str)
		{
			free(str);
			break ;
		}
		free(str);
	}
	close(fd);
	return (0);
}