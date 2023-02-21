/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:18:32 by quesera           #+#    #+#             */
/*   Updated: 2023/02/21 19:00:48 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	my_lst_free(t_list *find, t_list *head)
{
	if (find == NULL) //TODO : 필요성이 있는 예외처리인가?
		return ;
	t_list	*temp;

	temp = head;
	while (temp->next != NULL && temp->next != find)
		temp = temp->next;
	// while (head->next != NULL && head->next != find)
	// 	head = head->next;

	// if (head->next == NULL)
	// {
		if (head == NULL)
			free(head);
	// 	return ;
	// }

	if (find->save != NULL)
		free(find->save);
	temp->next = find->next;
	// head->next = find->next;
	find->next = NULL;
	free(find);

	// if (head->next == NULL)
	// {
	// 	if (head == NULL)
	// 		free(head);
	// 	return ;
	// }

	// if (head == NULL)
	// 	free(head);
	
	// find = NULL;
}

t_list	*my_lst_find(t_list **head, int f_fd)
{
	t_list	*temp;
//TODO : 3
//TODO : head마ㄴ들기 gnl()에 있던거 일단 올림
	// if (*head == NULL)
	// {
	// 	(*head) = malloc(sizeof(t_list));
	// 	if (!(*head))
	// 		return (NULL);
	// 	(*head)->fd = -1;
	// 	(*head)->next = NULL;
	// }
	temp = *head;
	while (temp)
	{
		if (temp->fd == f_fd)
		{
			//TODO : free_1
			// if (read(f_fd, NULL, 0) < 0)
			// {
			// 	my_lst_free(temp, *head);
			// 	return (0);
			// }
			return (temp);
		}
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

char	*my_save_buf(t_list *find, t_list *head)
{
	char		*ret;
	char		*temp;
	int			check;
	int			idx;

	ret = 0;
	while (ret == 0)
	{
		ft_memset(find->buf, 0, BUFFER_SIZE + 1);
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
				free(find->save); //TODO : 명준방식?
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
//TODO : 1
	// if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || check == 0)
	if (head == NULL)
	{
		head = malloc(sizeof(t_list));
		if (!head)
			return (NULL);
		head->fd = -1;
		head->next = NULL;
	}
	// find = my_lst_find(&head, fd); //TODO : 4
	/*

	if(find == NULL)
	{
		my_lst_free(find, head);
		return (NULL);
	}
	*/
	find = head;
	while (find && find->fd != fd)
	{
		find = find->next;
	}
	if (find == NULL)
	{
		if (head == NULL)
			free(head);
		return (NULL);
	}
		
	// if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || find == NULL)
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		
		// if (read(fd, NULL, 0) < 0)
		// {
		// 	find = head;
		// 	while (find)
		// 	{
		// 		if (find->fd == fd)
		// 			free(find);
		// 			// my_lst_free(find, head);
		// 		find = find->next;
		// 	}
		// }
		// if (head && head->next == NULL)
		// 	free(head);
		
		//TODO : 4 : segfault
		// if (find != NULL)
		// 	my_lst_free(find, head); //TODO : free_2 (leak x)
		
		// if (head->fd == -1 && head->next == NULL)
		// 	free(head);
			// my_lst_free(head, head);

		// if (read(fd, NULL, 0) <= 0)
		// {
		// 	find = my_lst_find(&head, fd);
		// 	my_lst_free(find, head);
			// if (head && head->next == NULL)
			// 	// my_lst_free(head, head);
			// 	free(head);
		// }
		return (0);
	}
	//TODO : 2
	// if (head == NULL)
	// {
	// 	head = malloc(sizeof(t_list));
	// 	if (!head)
	// 		return (NULL);
	// 	head->fd = -1;
	// 	head->next = NULL;
	// }
	find = my_lst_find(&head, fd);

	ret = my_save_buf(find, head);
	if (head->fd == -1 && head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	return (ret);
}
