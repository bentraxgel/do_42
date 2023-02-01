/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:52 by seok              #+#    #+#             */
/*   Updated: 2023/02/02 01:22:50 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_new_save(char *save, int idx)
{
	int	count;

	count = 0;
	while (save[idx + count])
		count++;
	if (count)
		return (ft_substr(save, idx, count));
	return (0);
}

char	*my_save_buf(char *buf, int check)
{
	static char	*save;
	int			find;
	char		*ret;

	ret = save;
	save = ft_strjoin(save, buf);
	free(ret);
	while (save[find])
	{
		if (save[find] == '\n')
		{
			ret = ft_substr(save, 0, find + 1)
			if (!ret)
				return (my_free(ret), 0);
			//save = my_new_save(save, find + 1);
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	int		check;

	check = 0;
	while (check >= 0)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		check = read(fd, buf, BUFFER_SIZE);
		my_save_buf(buf, check);
	}
}
