
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

int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	int		i;
	va_list ap;

	idx = -1;
	len = 0;
	va_start(ap, format);
	while (format[++idx] != '\0')
	{
		if (format[idx] == '%')
		{
			i = -1;
			while (SPECIFIER[++i])
			{
				if (format[idx + 1] == SPECIFIER[i])
				{
					len += my_specifier(SPECIFIER[i], &ap);
					idx++;
					break;
				}
			}
		}
		else
		{
			len++;
			write(1, &format[idx], 1);
		}
	}
	va_end(ap);
	return (len);
}

void	leaks()
{
	system("leaks -q a.out");
}
#include <stdio.h>
int	main()
{
	char *str;
	unsigned long long x;

	str = "ye";
	x = (unsigned long long)str;

	atexit(leaks);
	printf("ft_p\n");
	printf("\nft_%d", ft_printf("%p", str));
	printf("\norig_\n");
	printf("\nori_%d\n", (printf("%p", str)));


// 	printf("\njust : %p", (void *)str);
// 	printf("\njust : %llx", x);

}