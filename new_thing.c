/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:54:05 by seok              #+#    #+#             */
/*   Updated: 2023/01/31 19:15:56 by seok             ###   ########.fr       */
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



char *get_next_line(int fd)
{
	static t_list	*lst;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	lst = my_lst_find(&lst, fd);
	
}