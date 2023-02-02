/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:52 by seok              #+#    #+#             */
/*   Updated: 2023/02/02 21:35:08 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*my_lst_find(t_list *lst, int f_fd)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->fd == f_fd)
			return (temp);
		temp = temp->pre;
	}
	temp = lst;
	while (temp)
	{
		if (temp->fd == f_fd)
			return (temp);
		temp = temp->next;
	}
	while (lst->next)
		lst = lst->next;
	temp = malloc(sizeof(t_list));
	lst->next = temp;
	temp->pre = lst;
	temp->next = NULL;
	temp->fd = f_fd;
	return (temp);
}

char	*my_save_buf(char *buf, int check)
{
	static char	*save;
	int			find;
	char		*ret;

	find = 0;
	ret = 0;
	if (check == 0 && check != 0)
		return (save);
	save = ft_strjoin(save, buf);
	while (save[find])
	{
		if (save[find] == '\n')
		{
			ret = ft_substr(save, 0, find + 1);
			save = ft_substr(save, find + 1, ft_strlen(save) - (find + 1));
			break ;
		}
		find++;
	}
	return (ret);
}

char	*test_ret(t_list *lst, int fd, char *save)
{
	char		buf[BUFFER_SIZE];
	char		*ret;
	int			check;
	int			find;

	ret = 0;
	find = -1;
	while (ret == 0)
	{
		check = read(fd, buf, 3);
		if (check == 0 && save != 0)
			return (save);
		save = ft_strjoin(save, buf);
		while (save[++find])
		{
			if (save[find] == '\n')
			{
				ret = ft_substr(save, 0, find + 1);
				save = ft_substr(save, find + 1, ft_strlen(save) - (find + 1));
				return (ret);
			}
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			buf[BUFFER_SIZE];
	int				check;

	check = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	lst = my_lst_find(&lst, fd);
	return (test_ret(&lst, lst->fd));
	while (check >= 0)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		check = read(fd, buf, BUFFER_SIZE);
		my_save_buf(buf, check);
	}
}
