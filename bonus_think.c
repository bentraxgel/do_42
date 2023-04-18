
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
*/
typedef struct s_op
{
	int minus;
	int width;
	int dot;
	/*
	...
	flag내용들 구조체로 담기. my_specifier에서 읽어서 나온 수를 값으로 담음.
	*/
}t_op;

typedef struct s_rule
{
	int	sign;
	int	len;
	int	char_len;
	/*
	...
	flag에 따른 문자열 규율 정리. 
	t_op	flag;에 있는 내용읽고, 규율 만들기.
	*/
}t_rule;

/*
	t_op *my_option(t_op *flag, char ch, int f)
	{
	t_rule	option; //선언. flag에 따른 문자열 규율 정해져있음. 
	FLAG의 인덱스에 따라 어떤 flag인지 확인하여 해당 구조체에
	ch 값 넣음. if (width != 0){ atoi(t_op.ch)};
	
		my_fix_str(){	if ('-'랑 '+'랑 같이 있다면)
							sign 있거나 없거나; ...}
	}
	*/

int	my_specifier(const char *format, int idx, char **str, t_op *flag, va_list *ap)
{
	int		i;
	int		f;
	t_rule	option;

	i = -1;
	f = 0;
	while (FLAG[f]) // FLAG = "-.# +"
	{
		if (format[idx] == FLAG[f])
		{
			option = my_option(&flag, format[idx], f);
			idx++;
			f = 0;
		}
		else
			f++;
	}
	while (SPECIFIER[++i])
	{
		int	i;
		if (format[idx] == "cspdiuxX%"[i])
		{
			my_print(SPECIFIER[i], option, &ap); //서식지정자가 뭔지에 따라 달라지는 문자열 만들기 방법. 해서 출력하기
			return (idx);
		}
	}
	if (str != 0) //서식지정자 없을 경우 free
		free(*str);
	return (idx);
}
//^^^위에거는 보너스가지 구현 생각한것임! 하지만 구현하지 않을것..ㅎ
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
	t_op	flag;
	
	len = -1;
	idx = -1;
	start = 0;
	str = 0;
	tmp = 0;
	ch = 0;
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
			idx = my_specifier(format, idx, &str, &flag); //뭔지 문자배출
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