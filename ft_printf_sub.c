/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:34:58 by seok              #+#    #+#             */
/*   Updated: 2023/04/18 17:33:17 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	my_specifier(char ch, va_list *ap)
{
	if (ch == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (ch == 's')
		return (my_print(va_arg(*ap, char *)));
	else if (ch == 'p')
		return (my_va_void(va_arg(*ap, void *)));
	else
		return (my_va_int(ch, va_arg(*ap, int)));
	return (0);
}
