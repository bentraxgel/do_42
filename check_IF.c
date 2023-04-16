/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_IF.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:34:58 by seok              #+#    #+#             */
/*   Updated: 2023/04/16 19:30:30 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//TODO 제일 먼저 할 것!
// format[idx]를 주기보단, var_arg(ap, type)을 하여
// 바로 값을 주는건 어때?
// 또는
// 현재 문제점 : const char *fornmat이라서 strjoin을 못하고있는데,
// char c = format[idx];해서 c를 my_c로 보내는것
// 근데 어쩌피 서식지정자의 값이 중요한게 아니라 그로인해 받은
//가변인자의 값이 중요한거라 위에꺼가 더 맞는 말일듯? test필요
int	my_check_if(char ch)
{
	if (ch == 'c')
		return (sizeof(int));
	else if (ch == 's')
		return (sizeof(char *));
	else if (ch == 'p')
		return (sizeof(char *));
	else if (ch == 'd')
		return (sizeof(int));
	else if (ch == 'i')
		return (sizeof(char));
	else if (ch == 'u')
		return (sizeof(char));
	else if (ch == 'x')
	return (sizeof(char));
	else if (ch == 'X')
	return (sizeof(char));
	else if (ch == '%')//따로 표시 필요
		mreturn (sizeof(char));
	else
	{
	//이제 할 필요 없음
	// 	if (str != 0)
	// 		free (*str);
	// 	return (-1);
	}
	return (idx);
}
