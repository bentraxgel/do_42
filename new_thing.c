/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:54:05 by seok              #+#    #+#             */
/*   Updated: 2023/01/29 09:20:47 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*mt_lst_find(int f_fd, t_list **lst)
{
	//linked list 매개변수로 받는거 다시 공부해서 적용하자
	//ㅣ...정리해라
	int		cur;
	t_list	*newnode;

	newnode = 0;
	while (lst)
	{
		if (lst->fd == f_fd) 
			return (lst); //or break;
		lst = lst->next
	}
	if (lst == NULL)
	newnode = malloc(sizeof(t_list));
	//lst맨뒤에 새노드 추가
	//음....fd 다 읽었을때 free()해야할듯?

}

char *get_next_line(int fd)
{
	t_list	*lst;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	lst = my_lst_find(fd, *lst);
}