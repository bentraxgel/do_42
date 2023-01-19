/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:46:06 by seok              #+#    #+#             */
/*   Updated: 2023/01/06 16:35:38 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main()
{
	int		fd; 
	int		ren = 0; 
	char	buf[10];
	int		n = 4;
	char	**save;
	char	*tmp;
	int		i = 0;
	
	fd = open("text.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	//ren = read(fd, buf, n);
		save[i] = (char *)malloc(sizeof(char *) * n);
		tmp = *save;
		printf("tmp = %p\nsave = %p\n", tmp, save);
	while ((ren = read(fd, buf, n)) > 0)
	{
		*save = buf;
		printf("\n\n\tn = %d\n", ren);
		printf("buf_ADR\t:\t%p\nbuf\t:\t[%s]\n", buf, buf);
		printf("save_ADR\t:\t%p\nsave\t:\t[%s]\n", save, *save);
		save += n;
		
		//save += n;
	}
	printf("bufter\t:\t%d\n\n", ren);
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", buf[i]);
	}
	printf("\n========================\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", tmp[i]);
	}
}