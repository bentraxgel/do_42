
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
	while (SPECIFIER[++i])
	{
		//TODO 골라골라 편한걸로 골라
		// if (format[idx] == SPECIFIER[i])
		if (format[idx] == "cspdiuxX%"[i])
			return (SPECIFIER[i]);
	}
	if (str != 0) //서식지정자 없을 경우 free
		free(*str);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		idx;
	int		start;
	int		type_size;
	char	*str;
	char	*tmp;
	char	ch;
	va_list ap;
	
	len = -1;
	idx = -1;
	start = 0;
	str = 0;
	tmp = 0;
	c = 0;
	va_start(ap, format);
	
		printf("\n\nprintf:check_str : %s\n\n", str);

	while (*(format + (++idx)) != '\0')
	{
		printf("printf_start : %d", start);
		if (*(format + idx) == '%')
		{
			tmp = ft_substr(format, start, idx - start);
			str = ft_strjoin_free(str, tmp); //TODO 언젠간 free
			free(tmp);
			ch = my_specifier(format, idx, &str); //뭔지 문자배출
			if (ch)
				my_make_str(&ap, ch, &str); //TODO 이거 할 차례!!!
			start = idx + 2; //flag신경안쓴것
			idx++;
		}
		if (type_size < 0) //종료조건 (fail) 위에서 free함
			return (0);
	}
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