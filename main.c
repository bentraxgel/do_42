#include "get_next_line.h"

int	main()
{
	int	fd;
	char *ret;

	//ret = 0;
	fd = open("text.txt", O_RDONLY);
	printf("===main_print===\n");
	ret = get_next_line(fd);
	printf("1 ret : %s\n", ret);
	printf("---------------------------------------\n");
	ret = get_next_line(fd);
	printf("2 ret : %s\n", ret);
	printf("---------------------------------------\n");
	ret = get_next_line(fd);
	printf("3 ret : %s\n", ret);
	printf("---------------------------------------\n");
	ret = get_next_line(fd);
	printf("4 ret : %s\n", ret);
}