/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:18:32 by quesera           #+#    #+#             */
/*   Updated: 2023/02/21 22:46:51 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*my_lst_make(t_list **head)
{
	(*head) = malloc(sizeof(t_list));
	if (!(*head))
		return (NULL);
	(*head)->fd = -1;
	(*head)->next = NULL;
	return (*head);
}

t_list	*my_lst_find(t_list **head, int f_fd)
{
	t_list	*temp;

	if (*head == NULL)
		*head = my_lst_make(head);
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
	temp->save = NULL;
	temp->next = NULL;
	temp->fd = f_fd;
	return (temp);
}

int	my_save(t_list *find, char **ret, int check)
{
	char	*temp;
	int		idx;

	idx = BUFFER_SIZE + 1;
	while (idx--)
		find->buf[idx] = 0;
	check = 0;
	check = read(find->fd, find->buf, BUFFER_SIZE);
	find->save = ft_strjoin(find->save, find->buf);
	idx = -1;
	while (find->save[++idx])
	{
		if (find->save[idx] == '\n')
		{
			*ret = ft_substr(find->save, 0, idx + 1);
			temp = ft_substr(find->save, idx + 1, \
							ft_strlen(find->save) - (idx + 1));
			free(find->save);
			find->save = temp;
			return (1);
		}
	}
	return (check);
}

char	*my_save_buf(int fd, t_list **head)
{
	char		*ret;
	int			check;
	t_list		*find;

	ret = 0;
	check = 0;
	find = my_lst_find(head, fd);
	while (ret == 0)
	{
		check = my_save(find, &ret, check);
		if (check < 0 || (check == 0 && find->save == 0))
		{
			my_lst_free(find, *head);
			return (NULL);
		}
		else if (check == 0 && find->save != 0)
		{
			ret = ft_substr(find->save, 0, ft_strlen(find->save));
			my_lst_free(find, *head);
			return (ret);
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
	ret = my_save_buf(fd, &head);
	if (head->fd == -1 && head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	return (ret);
}
