/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_IF.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:34:58 by seok              #+#    #+#             */
/*   Updated: 2023/04/16 22:49:39 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	my_typesize(char ch, char **str, va_list *ap)
{
	if (ch == 'c')
		my_make_str(va_arg(ap, int));
	else if (ch == 's')
		return (va_arg(ap, char *));
	else if (ch == 'p')
		return (va_arg(ap, char *));
	else if (ch == 'd')
		return (va_arg(ap, int));
	else if (ch == 'i')
		return (va_arg(ap, int));
	else if (ch == 'u')
		return (va_arg(ap, int));
	else if (ch == 'x')
		return (va_arg(ap, int));
	else if (ch == 'X')
		return (va_arg(ap, int));
	else if (ch == '%') //else if 없이 단일로 써도 ok
	{
		ft_strjoin_free(*str, "%");
		return (0);
	}
	return (0);
}

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

void	my_make_str(va_list *ap, int type_size, char **str)
{

}