/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:42:16 by seok              #+#    #+#             */
/*   Updated: 2023/05/22 06:48:43 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_pivot(size_t start, size_t len, t_info *info)
{
	info->p1 = ((len - start) / 3) + start;
	info->p2 = ((len - start) / 3 * 2) + start;
	info->pa = 0;
	info->pb = 0;
	info->ra = 0;
	info->rb = 0;
}
