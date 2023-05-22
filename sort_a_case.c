/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:59:58 by seok              #+#    #+#             */
/*   Updated: 2023/05/21 23:27:55 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_first_case(t_stack *stack, t_info *info)
{
	command(RA, stack, info);
	command(PB, stack, info);
	command(PB, stack, info);
	command(RRA, stack, info);
	command(PA, stack, info);
	command(PA, stack, info);
}

void	a_second_case(t_stack *stack, t_info *info)
{
	command(RA, stack, info);
	command(PB, stack, info);
	command(PB, stack, info);
	command(RB, stack, info);
	command(RRA, stack, info);
	command(PA, stack, info);
	command(RRB, stack, info);
	command(PA, stack, info);
}

void	a_third_case(t_stack *stack, t_info *info)
{
	command(RA, stack, info);
	command(SA, stack, info);
	command(RRA, stack, info);
}

void	a_fourth_case(t_stack *stack, t_info *info)
{
	command(SA, stack, info);
}

void	a_fifth_case(t_stack *stack, t_info *info)
{
	command(RA, stack, info);
	command(RA, stack, info);
	command(PB, stack, info);
	command(RRA, stack, info);
	command(RRA, stack, info);
	command(PA, stack, info);
}
