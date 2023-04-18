/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:27:02 by seok              #+#    #+#             */
/*   Updated: 2023/04/18 17:41:14 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_hex_long(unsigned long long num)
{
	unsigned long long	n;
	int					len;
	char				*ret;

	n = num;
	len = 0;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	ret = malloc(len);
	if (!ret)
		return (0);
	ret[len] = 0;
	while (n > 0)
	{
		len--;
		if (0 <= (n % 16) && (n % 16) <= 9)
			ret[len] = (n % 16) + '0';
		else if (10 <= (n % 16) && (n % 16) <= 15)
			ret[len] = (n % 16) - 10 + 'a';
		n /= 16;
	}
	return (ret);
}
