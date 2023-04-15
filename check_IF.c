/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_IF.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:34:58 by seok              #+#    #+#             */
/*   Updated: 2023/04/15 23:16:06 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//TODO 제일 먼저 할 것!
// format[idx]를 주기보단, var_arg(ap, type)을 하여
// 바로 값을 주는건 어때?
// 또는
// 현재 문제점 : const char *fornmat이라서 strjoin을 못하고있는데,
// char c = format[idx];해서 c를 my_c로 보내는것
// 근데 어쩌피 서식지정자의 값이 중요한게 아니라 그로인해 받은
//가변인자의 값이 중요한거라 위에꺼가 더 맞는 말일듯? test필요
int	my_check_if(const char *format, int idx, char **str)
{
	if (format[idx] == 'c')
		*str = ft_strjoin_free(*str, format[idx]);
		my_c (str);
	else if (format[idx] == 's')
		my_s (str, format[idx]);
	else if (format[idx] == 'p')
		my_p (str);
	else if (format[idx] == 'd')
		my_d (str);
	else if (format[idx] == 'i')
		my_i (str);
	else if (format[idx] == 'u')
		my_u (str);
	else if (format[idx] == 'x')
		my_x(str);
	else if (format[idx] == 'X')
		my_X(str);
	else if (format[idx] == '%')
		my_per(str);
	else
	{
		if (str != 0)
			free (*str);
		return (-1);
	}
	return (idx);
}
