#include "header.h"

int	main()
{
	char **ret;
	char	buf[10];
	int		txt;
	int		fd;
	int	i = 0;
	int		size = 4;

//	ret = 0;
	//buf = 0;
	fd = open("text.txt", O_RDONLY);
	printf("fd : %d\n", fd);
	txt = read(fd, buf, size);
	printf("txt : %d\n", txt);
	ret[i] = (char *)malloc(sizeof(char) * (txt + 1));
	if (!ret[i])
		return (0);
	ret[i] = buf;
	printf("buf : %s\n", buf);
	printf("ret : %s\n", ret[i]);
}