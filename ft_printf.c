
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

int	my_print(char *str) //출력하는 함수
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	my_check(const char *format, int idx, char **str)
{
	if (format[idx] != 'c') //TODO specifier이 아닌 경우 test
	{
		if (str != 0)
			free(*str);
		return (-1);
	}
	*str = ft_strjoin_free(*str, "!check!");
	printf("\nmy_check : %c\n", *(format + idx));
	printf("check idx : %d\n", idx);
	return (idx + 1);
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
			str = ft_strjoin_free(str, tmp); //TODO 언젠간 free
			free(tmp);
			start = my_check(format, idx + 1, &str);
			printf("start : %d\n", start);
			idx = start;
		}
		if (idx < 0) //종료조건 (fail)
			return (0);
		printf("idx : %d\n", idx);
		printf("NOT\n");
	}
	printf("while_idx : %d\n", idx);
	if (start != idx) //서식지정자 이후 문자열까지 싹싹 긁어모아~
	{
		printf("In\n");
		tmp = ft_substr(format, start, idx - start);
		str = ft_strjoin_free(str, tmp);
		free(tmp);
	}
	if (str != 0) //종료조건 (true)
	{
		len = my_print(str);
		printf("\nfinish : %s\n", str);
	}
	free(str);

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
	atexit(leaks);
	printf("this is main : ");
	printf("ft_ : %d\n", ft_printf("hello%cye", 'A'));
	printf("\n\nothers\n");
	printf("ft_ : %d\n", ft_printf("hello%dye", 'A'));
	printf("\nEND\n");

}