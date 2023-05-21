/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:06 by seok              #+#    #+#             */
/*   Updated: 2023/05/22 01:37:10 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_command(t_list *command)
{
	//command = command->next한번 해야할것
	//while안에 마지막줄을 맨 위로 올리면 될듯?  "start\n"때문에!
	while (command)
	{
		if (!(ft_strncmp(command->content, "ra\n", 3)) ||\
			!(ft_strncmp(command->content, "rb\n", 3)))
		{
			command = r_print(command);
		}
		else if (!(ft_strncmp(command->content, "rra\n", 3)) ||\
			!(ft_strncmp(command->content, "rrb\n", 3)))
		{
			command = rr_print(command);
		}
		else if (!(ft_strncmp(command->content, "sa\n", 3)) ||\
			!(ft_strncmp(command->content, "sb\n", 3)))
		{
			command = s_print(command);
		}
		else
			ft_putstr_fd(command->content, STDOUT_FILENO);
		command = command->next;
	}
}

t_list	*r_print(t_list *command)
{
	t_list	*ret;

	ret = command;
	if (!(ft_strncmp(command->content, "ra\n", 3)) &&\
		 !(ft_strncmp(command->next->content, "rb\n", 3)))
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		ret = command->next;
	}
	else if (!(ft_strncmp(command->content, "rb\n", 3)) &&\
		 !(ft_strncmp(command->next->content, "ra\n", 3)))
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		ret = command->next;
	}
	else
		ft_putstr_fd(command->content, STDOUT_FILENO);
	return (ret); //다음 명령문을 읽어야하니까 ->next해서 주기..? 저쪽에서 ->next를 뒤에서 하면 pass
}

t_list	*rr_print(t_list *command)
{
	t_list	*ret;

	ret = command;
	if (!(ft_strncmp(command->content, "rra\n", 3)) &&\
		 !(ft_strncmp(command->next->content, "rrb\n", 3)))
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		ret = command->next;
	}
	else if (!(ft_strncmp(command->content, "rrb\n", 3)) &&\
		 !(ft_strncmp(command->next->content, "rra\n", 3)))
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		ret = command->next;
	}
	else
		ft_putstr_fd(command->content, STDOUT_FILENO);
	return (ret);
}

t_list	*s_print(t_list *command)
{
	t_list	*ret;

	ret = command;
	if (!(ft_strncmp(command->content, "sa\n", 3)) &&\
		 !(ft_strncmp(command->next->content, "sb\n", 3)))
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		ret = command->next;
	}
	else if (!(ft_strncmp(command->content, "sb\n", 3)) &&\
		 !(ft_strncmp(command->next->content, "sa\n", 3)))
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		ret = command->next;
	}
	else
		ft_putstr_fd(command->content, STDOUT_FILENO);
	return (ret);
}
