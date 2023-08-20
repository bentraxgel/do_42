/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkseo <dongkseo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:41:37 by dongkseo          #+#    #+#             */
/*   Updated: 2023/05/04 19:41:55 by dongkseo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	nb_len(long long nb)
{
	int	length;

	length = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

void	write_int(long long nb, char *arr, int *lev)
{
	if (nb > 9)
		write_int(nb / 10, arr, lev);
	arr[*lev] = (nb % 10 + '0');
	*lev += 1;
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			lev;
	char		*arr;

	nb = (long long)n;
	lev = 0;
	if (nb < 0)
	{
		nb *= -1;
		lev = 1;
		arr = (char *)malloc(nb_len(nb) + 2);
		if (!arr)
			return (NULL);
		arr[0] = '-';
	}
	else
		arr = (char *)malloc(nb_len(nb) + 1);
	if (!arr)
		return (NULL);
	write_int(nb, arr, &lev);
	arr[lev] = '\0';
	return (arr);
}
