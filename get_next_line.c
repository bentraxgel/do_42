/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:52 by seok              #+#    #+#             */
/*   Updated: 2023/02/02 14:32:01 by seok             ###   ########.fr       */
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
			//substr은 할당실패시 0으로 반환되기때문에 free노필요
			ret = ft_substr(save, 0, find + 1);
			//save = my_new_save(save, find + 1);
			//my_new_save도 이 함수에 같이 사용하면 될듯?
			save = ft_substr(save, find + 1, ft_strlen(save) - find);
			se\ok
			5 - 2 = 3
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
