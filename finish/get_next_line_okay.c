/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:18:32 by quesera           #+#    #+#             */
/*   Updated: 2023/02/21 20:37:41 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	my_lst_free(t_list *find, t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next != NULL && temp->next != find)
		temp = temp->next;
	if (head == NULL)
		free(head);
	if (find->save != NULL)
		free(find->save);
	temp->next = find->next;
	find->next = NULL;
	free(find);
}

t_list	*my_lst_find(t_list **head, int f_fd)
{
	t_list	*temp;

	if (*head == NULL)
	{
		(*head) = malloc(sizeof(t_list));
		if (!(*head))
			return (NULL);
		(*head)->fd = -1;
		(*head)->next = NULL;
	}
	temp = *head;
	while (temp)
	{
		if (temp->fd == f_fd)
			return (temp);
		temp = temp->next;
	}
	while ((*head)->next)
		(*head) = (*head)->next;
	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	(*head)->next = temp;
	ft_memset(temp, 0, sizeof(t_list));
	temp->fd = f_fd;
	return (temp);
}

char	*my_save_buf(t_list *find, t_list *head)
{
	char		*ret;
	char		*temp;
	int			check;
	int			idx;

	ret = 0;
	while (ret == 0)
	{
		idx = BUFFER_SIZE + 1;
		while (idx--)
			find->buf[idx] = 0;
		check = read(find->fd, find->buf, BUFFER_SIZE);
		find->save = ft_strjoin(find->save, find->buf);
		idx = -1;
		while (find->save[++idx])
		{
			if (find->save[idx] == '\n')
			{
				ret = ft_substr(find->save, 0, idx + 1);
				temp = ft_substr(find->save, idx + 1,\
								ft_strlen(find->save) - (idx + 1));
				free(find->save);
				find->save = temp;
				return (ret);
			}
		}
		if (check < 0)
		{
			my_lst_free(find, head);
			return (NULL);
		}
		else if (check == 0 && find->save != 0)
		{
			ret = ft_substr(find->save, 0, ft_strlen(find->save));
			my_lst_free(find, head);
			return (ret);
		}
		else if (check == 0 && find->save == 0)
		{
			my_lst_free(find, head);
			return (NULL);
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*find;
	char			*ret;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		find = head;
		while (find)
		{
			if (find->fd == fd)
			{
				my_lst_free(find, head);
				return (NULL);
			}
			find = find->next;
		}
		return (0);
	}
	find = my_lst_find(&head, fd);
	ret = my_save_buf(find, head);
	if (head->fd == -1 && head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	return (ret);
}
