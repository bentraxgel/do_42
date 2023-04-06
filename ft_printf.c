
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:16:50 by seok              #+#    #+#             */
/*   Updated: 2023/04/02 15:37:40 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h> //TODO del

int	my_check(char *format, int idx)
{
	if (*(format + idx) == 'c')
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	char	*str;
	va_list ap;
	
	len = 0;
	idx = -1;
	str = 0;
	va_start(ap, format);
	
	while (*(format + idx++))
	{
		if (*(format + idx) == '%')
		{
			str = malloc(idx);
			idx = my_check(format, idx + 1);
		}
	}
	// printf ("va_start : %p\n", ap);
	// // while (*format)
	// for (int i = 0; i < 3; i++)
	// {
	// 	printf("%c\n", va_arg(ap, int));
	// 	//format += sizeof(char);
	// }
	// va_end(ap);
	//return (num);
	return (len);
}
