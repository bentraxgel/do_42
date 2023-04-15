/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_IF.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:34:58 by seok              #+#    #+#             */
/*   Updated: 2023/04/15 22:46:38 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
