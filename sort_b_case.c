/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:20:35 by seok              #+#    #+#             */
/*   Updated: 2023/05/22 00:26:54 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_first_case(t_stack *stack, t_info *info)
{
	command(PA, stack, info);
	command(PA, stack, info);
	command(RB, stack, info);
	command(SA, stack, info);
	command(PB, stack, info);
	command(PB, stack, info);
	command(RRB, stack, info);
}

void	b_second_case(t_stack *stack, t_info *info)
{
	command(PA, stack, info);
	command(RB, stack, info);
	command(RB, stack, info);
	command(PB, stack, info);
	command(RRB, stack, info);
	command(RRB, stack, info);
}

void	b_third_case(t_stack *stack, t_info *info)
{
	command(RB, stack, info);
	command(SB, stack, info);
	command(RRB, stack, info);
}

void	b_fourth_case(t_stack *stack, t_info *info)
{
	command(PA, stack, info);
	command(PA, stack, info);
	command(RB, stack, info);
	command(PB, stack, info);
	command(PB, stack, info);
	command(RRB, stack, info);
}

void	b_fifth_case(t_stack *stack, t_info *info)
{
	command(SB, stack, info);
}