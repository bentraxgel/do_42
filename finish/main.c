#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	leak_check()
{
	system("leaks a.out");
}

int	main(void)
{
	int		idx;
	int		fd;
	char	*str;

	atexit(leak_check);
	idx = 1;
	fd = open("text.txt", O_RDWR);
	printf("1_fd : %d\n", fd);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	close(fd);
	fd = open("text.txt", O_RDWR);
	printf("1_fd : %d\n", fd);
	while (1)
	{
		str = get_next_line(fd);
		printf("%d: <%s\n", idx, str);
		idx++;
		if (!str)
		{
			free(str);
			break ;
		}
		free(str);
	}
	close(fd);
	return (0);
}