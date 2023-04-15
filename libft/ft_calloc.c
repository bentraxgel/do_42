/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:35 by seok              #+#    #+#             */
/*   Updated: 2022/12/20 09:46:35 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// TODO 윈도우에서 안됨
#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count < 0 || size < 0)
		return (0);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (SIZE_MAX / size < count)
		return (0);
	ret = (void *)malloc(count * size);
	if (!ret)
		return (0);
	ft_memset(ret, 0, count * size);
	return (ret);
}
