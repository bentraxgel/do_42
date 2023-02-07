/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:52 by seok              #+#    #+#             */
/*   Updated: 2023/02/07 22:04:51 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*my_lst_find(t_list **lst, int f_fd)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->fd == f_fd)
			return (temp);
		temp = temp->next;
	}
	while ((*lst)->next)
		lst = (*lst)->next;
	temp = malloc(sizeof(t_list));
	(*lst)->next = temp;
	temp->next = NULL;
	temp->fd = f_fd;
	return (temp);
}

void	my_lst_free(t_list *find, t_list *lst)
{
	while(lst->next == find)
		lst = lst->next;
	find->fd = 0;
	lst->next = find->next;
	find->next = NULL;
	free(find);
}

char	*my_save_buf(t_list *find, t_list *lst)
{
	char		*ret;
	int			check;
	int			idx;

	ret = 0;
	idx = -1;
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

	check = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	find = my_lst_find(&lst, fd);
	return (my_save_buf(find, &lst));
}
