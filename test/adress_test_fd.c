#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char buf [4];
	printf("first : %p\t%s\n", buf, buf);
	int fd = open("text.txt" , O_CREAT);//로 파일을 열거나 없으면 생성해주고
	printf("%d\t", fd);
	fd = open("text.txt" , O_CREAT);//로 파일을 열거나 없으면 생성해주고
	printf("%d\n", fd);
	off_t	off;
	off = lseek(fd , sizeof(buf), SEEK_SET);
	printf("offset : %lld\n", off);


	read(fd, buf, sizeof(buf));// {<-sizeof(buf)는 4}
	
	off = lseek(fd , sizeof(buf), SEEK_SET);
	printf("second : %p\t%s\n", buf, buf);
	printf("offset : %lld\n", off);

	write(fd, buf, sizeof(buf));
	off = lseek(fd , sizeof(buf), SEEK_SET);
	printf("third : %p\t%s\n", buf,  buf);
	printf("offset : %lld\n", off);

}
