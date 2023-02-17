/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:12:45 by seok              #+#    #+#             */
/*   Updated: 2023/02/18 02:13:17 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*my_lst_find(t_list **head, int f_fd)
{
	t_list	*temp;

	// if (*head == 0)
	// {
	// 	*head = malloc(sizeof(t_list));
	// 	(*head)->fd = -1;
	// 	(*head)->next = NULL;
	// 	// return (*head);
	// }
	// if (*head == 0)
	// {
	// 	temp = malloc(sizeof(t_list));
	// 	temp->fd = f_fd;
	// 	temp->next = NULL;
	// 	*head = temp;
	// 	return (temp);
	// }
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

// void	my_lst_free(t_list *find, t_list *head)
// {
// 	// head = head + 0;
// 	// find = find+0;
// 	//TODO : check while(!=)
// 	//need head leak check
// 	// if (head->next == find)
// 	while(head->next != find)
// 		head = head->next;
// 	find->fd = 0;
// 	head->next = find->next;
// 	find->next = NULL;
// 	free(find);
// }
void my_lst_free(t_list *find, t_list *head)
{
	if (find == NULL) //TODO : 필요성이 있는 예외처리인가?
		return ;
    while (head->next != NULL && head->next != find)
        head = head->next;

    if (head->next == NULL)
        return ;
	if (find->save != NULL)
		free(find->save);
    head->next = find->next;
    find->next = NULL;
    free(find);
}

// char	*my_save_buf(t_list *find, t_list *head)
// {
// 	char		*ret;
// 	char		*temp;
// 	int			check;
// 	int			idx;

// 	ret = 0;
// 	//idx = -1;
// 	while (ret == 0)
// 	{
// 		ft_memset(find->buf, 0, BUFFER_SIZE + 1);
// 		check = read(find->fd, find->buf, BUFFER_SIZE);
// 		if (check < 0)
// 		{
// 			my_lst_free(find, head);
// 			return (NULL);
// 		}
// 		else if (check == 0 && find->save != 0)
// 		{
// 			ret = ft_substr(find->save, 0, ft_strlen(find->save));
// 			my_lst_free(find, head);
// 			return (ret);
// 		}
// 		else if (check == 0 && find->save == 0)
// 		{
// 			// ret = ft_strdup("");
// 			my_lst_free(find, head);
// 			return (NULL);
// 		}
// 		else
// 		{
// 			find->save = ft_strjoin(find->save, find->buf);
// 			idx = -1;
// 			while (find->save[++idx])
// 			{
// 				if (find->save[idx] == '\n')
// 				{
// 					ret = ft_substr(find->save, 0, idx + 1);
// 					temp = ft_substr(find->save, idx + 1,\
// 								 ft_strlen(find->save) - (idx + 1));
// 					// if (find->save != NULL)
// 					// {
// 						free(find->save); //TODO : 명준방식?
// 					// 	find->save = 0;
// 					// }
// 					// find->save = ft_substr(temp, 0, ft_strlen(temp));
// 					find->save = temp;
// 					// printf("save: %s\n", find->save);
// 					// printf("buff: %s\n", find->buf);
// 					// printf("ret: %s\n", ret);
// 					return (ret);
// 				}
// 			}
// 		}
// 	}
// 	return (ret);
// }
char	*my_save_buf(t_list *find, t_list *head)
{
	char		*ret;
	char		*temp;
	int			check;
	int			idx;

	ret = 0;
	//idx = -1;
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
				// if (find->save != NULL)
				// {
					free(find->save); //TODO : 명준방식?
				// 	find->save = 0;
				// }
				// find->save = ft_substr(temp, 0, ft_strlen(temp));
				find->save = temp;
				// printf("save: %s\n", find->save);
				// printf("buff: %s\n", find->buf);
				// printf("ret: %s\n", ret);
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
			// ret = ft_strdup("");
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
		return (0);
	//printf("before : %s, %p",lst->save, lst);
	//TODO : head 할당 꼭 여기서 할 필요 없긴 함.
	if (head == NULL)
	{
		head = malloc(sizeof(t_list));
		if (!head)
			return (NULL);
		head->fd = -1;
		head->next = NULL;
	}
	find = my_lst_find(&head, fd);
	ret = my_save_buf(find, head);
	if (head && head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	return (ret);
}