/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:52 by seok              #+#    #+#             */
/*   Updated: 2023/01/20 05:14:12 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_new_save(char *save, int find) //save = new((save - ret))
{
	int	count;

	count = 0;
	while (save[find + count])
		count++; //횟수세는거 정확하게 확인.
	if(count)
		return (ft_substr(save, find, count));
	return (save);
}

char	*my_save_buf(char *buf, int check) //ret반환
{
	static char	*save;
	int			find;
	char		*ret;

	ret = save;
	save = ft_strjoin(save, buf); //memset대신 strlcpy할겨?
	//strlcpy()를 사용한다면, 널보장되기때문에 ret = strlcpy();return(ret);
	//>strlcpy(save, buf, len); 에서 buf = null이라면??0이돼야하지않을까
	//>buf에 아무것도 안들어간다면 read()가 EOF라는거 아닌가? ->확인필요
	//
	//memset()을 사용한다면, 널보장은 안되지만 함수를 살짝 바꿔서 마지막에 널을 넣는다면
	//>return(memset()); 으로 반환 가능. ->단점 :join도 수정해야함.
	free(ret);
	while (save[find])
	{
		if (save[find] == '\n')
		{
			ret = malloc(find + 2); //동적할당할 크기 확실히 알기
			if (!ret)
				return(my_free(ret), 0);
			save = my_new_save(save, find);
		}
	}
	free(ret); //어찌될진 모르지만 leak잊지말자 - 이부분에서 필요한지 생각해보기
	return (0);
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