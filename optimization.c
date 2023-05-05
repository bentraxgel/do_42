/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:06 by seok              #+#    #+#             */
/*   Updated: 2023/05/05 09:16:39 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
TODO
ra, rb -> rr
rra, rrb -> rrr;
로 확인하여 바꾸는 함수인데 잘 바뀌는지, free는 잘 돼서 leak안나는지 확인해야함.
leak은 window에서 확인못한느거 잊지말긔
*/
void	optimization(t_info *stack)
{
	t_list	*check;
	t_list	*tmp;

	check = stack->command;
	char	*content = stack->command->content;
	if ((check->content == "ra\n" && check->next->content == "rb\n") ||\
		check->content == "rb\n" && check->next->content == "ra\n")
	{
		tmp = check->next;
		check->content = "rr\n";
		check->next = tmp->next;
		free(tmp);
	}
}