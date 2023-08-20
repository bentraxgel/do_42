#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 쓰레드 함수
// 1초를 기다린후 아규먼트^2 을 리턴한다.

/*
    실행중인 쓰레드를 detached(분리)상태로 만든다.
    pthread_detach(:3)함수는 쓰레드 식별자th를 가지는 쓰레드를 메인쓰레드에서 분리 시킨다. 
    이것은 th를 가지는 쓰레드가 종료되는 즉시 쓰레드의 모든 자원을 되돌려(free)줄 것을 보증한다. 
    detach상태가 아닐경우 쓰레드가 종료한다고 하더라도 
    pthread_join(3)을 호출하지 않는 한 자원을 되돌려주지 않는다.

*/
void *t_function(void *data)
{
	printf("Thread Start\n");
    char a[100000];
    int num = *((int *)data);
    // sleep(5);
	printf("Thread end\n");
	return ((int *)num);
}

int main()
{
    pthread_t p_thread;
    int thr_id;
    int status;
    int a = 100;

    printf("Before Thread\n"); 
    thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
    // 식별번호 p_thread 를 가지는 쓰레드를 detach 
    // 시켜준다. 
    pthread_detach(p_thread);
	printf("I'm done\n");
    pause();	// 시그널이 발생하기 전까지 계속 대기
    printf("get signal\n");
    return 0;
}