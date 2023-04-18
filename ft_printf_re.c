
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
//TODO libft ft_strlen수정함_출력결과 다시 확인하기
#include "printf.h"
#include <stdio.h> //TODO del

void	leaks()
{
	system("leaks a.out");
}



int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	int		i;
	va_list ap;

	idx = 0;
	va_start(ap, format);
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			i = -1;
			while (SPECIFIER[++i])
			{
				if (format[idx + 1] == SPECIFIER[i])
				{
					my_specifier(SPECIFIER[i]);
					idx++;
					break ;
				}
				else
					return (-1);
			}
		}
		else
			write(1, format[idx], 1);
	}
	va_end(ap);
	return (len);
}

int	main()
{
	atexit(leaks);
	printf("this is main : ");
	printf("ft_ : %d\n", ft_printf("hello%cye", 'A'));
	printf("\n\nothers\n");
	printf("ft_ : %d\n", ft_printf("hello%dye", 'A'));
	printf("\n\nothers\n");
	printf("ft_ : %d\n", ft_printf("hello%d%s", 'A'));
	printf("\nEND\n");

}