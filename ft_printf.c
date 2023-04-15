
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

/*
option인지 flag인지 그거
	int	i;
	while (OPTION[i])
	{
		i = 0;
		if (format[idx] == OPTION[i])
		{
			//배열에 값 1로 바꿈 (check하는것)
			idx++;
			i++;
		}
	}
*/
void	my_c(char **str, const char *c)
{
	*str = ft_strjoin_free(*str, c);
}
int	my_check(const char *format, int idx, char **str)
{
	int		i;
	char	c;

	i = -1;
	c = 0;
	printf("1:check_str : %s\n", *str);
	while (SPECIFIER[++i])
	{
		//TODO 골라골라 편한걸로 골라
		// if (format[idx] == SPECIFIER[i])
		if (format[idx] == "cspdiuxX%"[i])
		{
			c = SPECIFIER[i];
			break ;
		}
	}
	if (c == 0) //TODO specifier이 아닌 경우 test
	{
		if (str != 0)
			free(*str);
		return (-1);
	}
	my_c(str, &format[idx]);
	*str = ft_strjoin_free(*str, "!check!");
	return (idx);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	int		start;
	char	*str;
	char	*tmp;
	va_list ap;
	
	len = -1;
	idx = -1;
	str = 0;
	tmp = 0;
	start = 0;
	va_start(ap, format);
	
		printf("\n\nprintf:check_str : %s\n\n", str);

	while (*(format + ++idx) != '\0')
	{
		printf("printf_start : %d", start);
		if (*(format + idx) == '%')
		{
			tmp = ft_substr(format, start, idx - start);
			str = ft_strjoin_free(str, tmp); //TODO 언젠간 free
			free(tmp);
			idx = my_check(format, idx + 1, &str);
			start = idx + 1;
			printf("start : %d\n", start);
		}
		if (idx < 0) //종료조건 (fail) 위에서 free함
			return (0);
		printf("idx : %d\n", idx);
		printf("NOT : %c\n", format[idx]);
	}
	printf("while_idx : %d\n", idx);
	if (start + 1 != idx) //서식지정자 이후 문자열까지 싹싹 긁어모아~
	{
		printf("In\n");
		tmp = ft_substr(format, start, idx - start);
		str = ft_strjoin_free(str, tmp);
		free(tmp);
	}
	if (str != 0) //종료조건 (true)
	{
		printf("\nfinish : %s\n", str);
		while (*(str + (++len)))
			ft_putchar_fd(*(str + len), 1);
		printf("\n");
		// len = my_write(str);
	}
	free(str);
	str = NULL;

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
	printf("\n\nothers\n");
	printf("ft_ : %d\n", ft_printf("hello%d%s", 'A'));
	printf("\nEND\n");

}