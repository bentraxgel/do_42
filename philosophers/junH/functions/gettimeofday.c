#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
	#include <sys/time.h>

	int gettimeofday(struct timeval *tv, struct timezone *tz);
	현재 시간을 가져오고 시스템의 시간값을 설정한다.
	반환되는 값은 1970-01-01 00:00 부터 함수가 호출된 시간까지의 ms 값 입니다.

	timezone 은 잘 사용되지 않으며, timeval 의 구조는 다음과 같습니다.
	struct timeval {
		time_t      tv_sec;
		suseconds_t tv_usec;
	}
	tv_sec 는 초, suseconds_t 는 마이크로초를 저장합니다.
*/

long	get_time_diff_in_ms(struct timeval end, struct timeval start)
{
	long	diff;

	diff = (((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) / 1000));
	return (diff);
}

int main()
{
    struct timeval start;
    struct timeval end;
	long	diff;

    gettimeofday(&start, NULL);
	usleep(1000 * 1000); // 1s == 1000ms
	gettimeofday(&end, NULL);
    diff = get_time_diff_in_ms(end, start);
    printf("%ld ms\n", diff);	// 1000 ms
    return 0;
}