/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:28:27 by joonhan           #+#    #+#             */
/*   Updated: 2022/11/11 15:09:55 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f' || c == '\t')
		return (TRUE);
	return (FALSE);
}

static int	is_sign_symbol(char c)
{
	if (c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

static int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static long long	calculate_result(const char *str, int i, int sign)
{
	long long	result;
	long long	temp;

	result = 0;
	while (*(str + i) != '\0')
	{
		temp = result;
		if (is_numeric(*(str + i)) == FALSE)
			return (ERROR);
		result = (result * 10) + (*(str + i) - '0');
		i += 1;
		if (sign == -1 && temp > result)
			result = 0;
		else if (sign == 1 && temp > result)
			result = -1;
		if (temp > 0 && result <= 0)
			break ;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			sign_cnt;
	long long	result;

	i = 0;
	sign = 1;
	sign_cnt = 0;
	while (is_whitespace(*(str + i)))
		i += 1;
	while (is_sign_symbol(*(str + i)))
	{
		if (*(str + i) == '-')
			return (ERROR);
		i += 1;
		sign_cnt += 1;
		if (sign_cnt >= 2)
			return (ERROR);
	}
	result = calculate_result(str, i, sign);
	return ((int)result * sign);
}
