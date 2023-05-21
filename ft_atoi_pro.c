/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:24:20 by seok              #+#    #+#             */
/*   Updated: 2023/04/30 14:24:20 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_isspace_pro(int c)
{
	return (c == 32 || (8 < c && c < 14));
}

void	my_check_digit(const char *str)
{
	if (ft_strlen(str) != 1 && (*str == '-' || *str == '+'))
		str++;
	while (*str)
	{
		if (ft_isdigit((int)*str))
			str++;
		else
			my_error();
	}
}

void	my_check_limit(long long num)
{
	if (num < -2147483648 || 2147483647 < num)
		my_error();
}

int	ft_atoi_pro(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace_pro(*str))
		str++;
	my_check_digit(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + *str - '0';
		str++;
	}
	my_check_limit(result * sign);
	return (result * sign);
}
