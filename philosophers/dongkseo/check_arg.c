/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkseo <dongkseo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:50:04 by dongkseo          #+#    #+#             */
/*   Updated: 2023/05/04 19:50:34 by dongkseo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (*s1 == '+')
		s1++;
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_check(int ac, char **av)
{
	int		i;
	t_check	t;

	i = 0;
	while (++i < ac)
	{
		t.data = ft_atoi(av[i]);
		t.itoa_tmp = ft_itoa(t.data);
		if (ft_strcmp(av[i], t.itoa_tmp) == -1 || t.data < 0)
		{
			free(t.itoa_tmp);
			return (1);
		}
		if ((i == 1 && t.data <= 0) || (i == 2 && t.data <= 0))
			return (1);
		free(t.itoa_tmp);
	}
	return (0);
}
