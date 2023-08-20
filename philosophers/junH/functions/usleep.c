#include <unistd.h>
#include <stdio.h>

/*
	sleep 과 usleep의 차이는 
	sleep 은 second 를 받고, 
	usleep 은 microsecond 를 받는다.

	1 second == 1,000 millisecond
	1 millisecond == 1,000 microsecond
	1 microsecond == 1,000 nanosecond
*/
int main( void)
{
	while (1)
	{
		printf( "2초 마다 문자열 출력\n");
    	usleep( 2 * 1000 * 1000 );	// sleep(2) 과 동일
	}
}