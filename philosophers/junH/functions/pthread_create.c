#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

/*
int 
pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

pthread_create는 새로운 쓰레드를 생성한다. 
새로운 쓰레드는 start_routine 함수를 arg 아규먼트로 실행시키면서 생성된다. 
생성된 쓰레드는 pthread_exit(3) 을 호출하거나 
start_routine 에서 return 할경우 제거된다.

attr 아규먼트는 쓰레드와 관련된 특성을 지정하기 위한용도로 사용된다. 
이에 대한 내용은 pthread_attr_init(3) 을 참고해야 한다. 
attr 을 NULL 로 할경우 기본 특성으로 지정된다. 리눅스에서의 쓰레드는
joinable 과 non real-time 스케쥴 정책을 기본특성으로 한다.
*/

// 쓰레드 함수
void *test(void *data)
{
    int i;
    int a = *(int *)data;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i*a);
    }
    // return (void *)(i * 100);
    return (void *)(i * 100);
}

int main()
{
    int a = 100;
    pthread_t thread_t;
    int status;

    // 쓰레드를 생성한다. 
    if (pthread_create(&thread_t, NULL, test, (void *)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }
    printf("thread_t : %x\n", (unsigned int)thread_t);
    // 쓰레드가 종료되기를 기다린후 
    // 쓰레드의 리턴값을 출력한다. 
    pthread_join(thread_t, (void **)&status);
    printf("Thread End %d\n", status);
    return (0);
}