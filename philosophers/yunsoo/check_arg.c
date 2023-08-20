/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:08:30 by suhyun            #+#    #+#             */
/*   Updated: 2023/08/01 23:49:14 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ph.h"

int	check_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (ERROR);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	ret;
	int					sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	if (ret > 2147483648 && sign == -1)
		return (-1);
	if (ret > 2147483647 && sign == 1)
		return (0);
	return ((int)ret * sign);
}

int	err_msg(char *msg)
{
	printf("%s\n", msg);
	return (ERROR);
}

int	check_arg(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (err_msg("Parameter Error"));
	i = 1;
	while (i < ac)
	{
		if (check_num(av[i]) || ft_atoi(av[i]) <= 0)
			return (err_msg("Invalid Arguments"));
		i++;
	}
	return (0);
}
