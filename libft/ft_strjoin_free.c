 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:24:06 by seok              #+#    #+#             */
/*   Updated: 2022/12/18 14:24:06 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, s1_len);
	free(s1);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = 0;
	return (ret);
}
