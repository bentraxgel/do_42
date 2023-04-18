/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_IF.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:34:58 by seok              #+#    #+#             */
/*   Updated: 2023/04/18 11:38:20 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	my_c(char c, char **str)
{
	*str = ft_strjoin_free(*str, c);
}

void	my_specifier(char ch)
{
	if (format[idx] == 'c')
		my_c ;
	else if (format[idx] == 's')
		my_s (str, format[idx]);
	else if (format[idx] == 'p')
		my_p ;
	else if (format[idx] == 'd')
		my_d ;
	else if (format[idx] == 'i')
		my_i ;
	else if (format[idx] == 'u')
		my_u ;
	else if (format[idx] == 'x')
		my_x;
	else if (format[idx] == 'X')
		my_X;
	else if (format[idx] == '%')
		my_per;
	else
	{
		if (str != 0)
			free (*str);
		return (-1);
	}
	return (idx);
}

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

}

void	my_make_str(va_list *ap, int type_size, char **str)
{

}