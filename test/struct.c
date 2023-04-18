/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:18:31 by seok              #+#    #+#             */
/*   Updated: 2023/04/17 15:24:37 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

typedef struct s_op
{
	int	a;
	int	b;
}t_op;

void	func(t_op *n)
{
	n->a = 10;
	n->b = 11;
}

int	main()
{
	t_op	num;
	ft_memset(&num, 0, sizeof(num));
	// ft_memset((void *)&num, 0, sizeof(num));
	printf("before : %d %d\n", num.a, num.b);
	func(&num);
	printf("after : %d %d\n", num.a, num.b);
}