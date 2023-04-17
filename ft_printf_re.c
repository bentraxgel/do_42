
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

void	my_c(char c, char **str)
{
	*str = ft_strjoin_free(*str, c);
}

char	my_specifier(const char *format, int idx, char **str)
{
	int		i;
	int		type_size;

	i = -1;
	type_size = 0;
	if (format[idx] == "cspdiuxX%"[i])
		return (SPECIFIER[i]);
	else
		//그냥 출력
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	int		start;
	va_list ap;
	
	idx = 0;
	va_start(ap, format);
	while (format[idx]) != '\0')
	{
		if (*(format + idx) == '%')
		{
			ch = my_specifier(format, idx, &str); //뭔지 문자배출
			idx++;
		}
		else
		{
			
		}
	}
	va_end(ap);
	//return (num);
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