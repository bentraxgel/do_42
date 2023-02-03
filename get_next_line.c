/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:52 by seok              #+#    #+#             */
/*   Updated: 2023/02/03 22:29:23 by seok             ###   ########.fr       */
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

char	*my_save_buf(t_list *lst)
{
	char		*ret;
	int			check;
	int			find;

	ret = 0;
	find = -1;
	while (ret == 0)
	{
		ft_memset(lst->buf, 0, BUFFER_SIZE + 1);
		check = read(lst->fd, lst->buf, BUFFER_SIZE);
		if (check == 0 && lst->save != 0)
			return (lst->save);
		lst->save = ft_strjoin(lst->save, lst->buf);
		while (lst->save[++find])
		{
			if (lst->save[find] == '\n') 
			{
				ret = ft_substr(lst->save, 0, find + 1);
				lst->save = ft_substr(lst->save, find + 1,\
							ft_strlen(lst->save) - (find + 1));
				return (ret);
			}
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list	*find;
	char			buf[BUFFER_SIZE];
	int				check;

	check = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	find = my_lst_find(&lst, fd);

	//pre : 굳이 없어도 괜춘. 왜냐면 *lst 자체는 그냥 head개념으로 두고, lst->fd == f_fd;인 주소는
	//t_list find;에 저장해서 다른 함수에 사용하면 되니깐!
	//낼 해보고 바로 평가 고고
	return (my_save_buf(&lst));
}
