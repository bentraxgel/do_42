/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:02:51 by seok              #+#    #+#             */
/*   Updated: 2023/01/16 23:25:43 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*save;
	int		check;

	if (fd || BUFFER_SIZE < 0)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE);
	save = malloc(BUFFER_SIZE);
	while (check >= 0) //read할게 있는경우
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check > 0)
		{
			save = ft_strjoin(save, buf);
			ft_memset(buf, 0, BUFFER_SIZE);
		}
		else if (check == 0) //EOF
		{
			printf("EOF\n");
			break ;
		}
	}
	return (0);
}