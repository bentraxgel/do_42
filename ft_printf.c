
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

#include "printf.h"
#include <stdio.h> //TODO del

int	my_check(const char *format, int idx, char **str)
{
	*str = ft_strjoin(*str, "!check!");
	printf("\nmy_check : %c\n", *(format + idx));
	return (idx++);
	// if (*(format + idx) == 'c')
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	int		start;
	char	*str;
	char	*tmp;
	va_list ap;
	
	len = 0;
	idx = -1;
	str = 0;
	tmp = 0;
	va_start(ap, format);
	
	while (*(format + ++idx) != '\0')
	{
		if (*(format + idx) == '%')
		{
			tmp = ft_substr(format, start, idx - start);
			str = ft_strjoin(str, tmp); //TODO 언젠간 free
			free(tmp);
			start = my_check(format, idx + 1, &str);
			idx = start;
		}
		printf("NOT\n");
	}
	printf("finish : %s\n", str);

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

int	main()
{
	printf("this is main : ");
	printf("ft_ : %d\n", ft_printf("hello%cye", 'A'));
	printf("\nEND\n");

}