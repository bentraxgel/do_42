/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:52 by seok              #+#    #+#             */
/*   Updated: 2023/01/31 02:50:20 by seok             ###   ########.fr       */
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
//ret반환 : free(ret)할 필요없는 이유 : 반환할 문자열에 대해서는 메모리신경을 쓰지 않아도 된다??
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
			//ret = malloc(sizeof(char) * (find + 2));
			ret = malloc(find + 2);
			ft_memcpy(ret, save, find + 1);
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
