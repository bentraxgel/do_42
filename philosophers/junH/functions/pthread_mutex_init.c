/*
뮤텍스(mutex)는 쓰레드가 공유하는 데이터 영역을 보호하기 위해서 사용되는 도구이다. 
pthread_mutex_init는 뮤텍스 객체를 초기화 시키기 위해서 사용한다.

첫번째 인자인 mutex는 초기화 시킬 mutex객체이다. 
초기화 시킬 때 뮤텍스의 특징을 정의할 수 있는데, 이는 두번째 인자인 attr를 통해서 이루어진다. 
기본 뮤텍스 특징을 사용하길 원한다면 NULL을 이용하면 된다.

뮤텍스는 "fast", "recurisev", "error checking"의 3가지 종류중 하나를 선택할 수 있으며, 
기본적으로 "fast"가 사용된다.

https://www.joinc.co.kr/w/man/3/pthread_mutex_lock
*/

// #include <pthread.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// // 뮤텍스 객체 선언
// pthread_mutex_t	mutex_lock;
// int	g_count = 0; // 쓰레드 공유자원. 

// void	*t_function(void *data)
// {
//     int		i;
//     char*	thread_name = (char *)data;
    
//     pthread_mutex_lock(&mutex_lock);
//     g_count = 0;// 쓰레드마다 0부터 시작.
//     for (i = 0; i < 3; i++)
// 	{
// 		printf("%s COUNT %d\n", thread_name, g_count);
// 		g_count++;  // 쓰레드 공유자원, 1증가.
// 		sleep(1);
// 	}
// 	pthread_mutex_unlock(&mutex_lock);
// }

// int main()
// {
// 	pthread_t	p_thread1;
// 	pthread_t	p_thread2;
// 	int			status;

// 	pthread_mutex_init(&mutex_lock, NULL);
// 	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
// 	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
// 	pthread_join(p_thread1, (void *)&status);
// 	pthread_join(p_thread2, (void *)&status);

//     pthread_mutex_destroy(&mutex_lock);
// }

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct  s_data
{
    int state;
    pthread_mutex_t mutex;
}   t_data;

void *count(void *data)
{
    pthread_mutex_lock(&((t_data *)data)->mutex);

    //======== critical section =============
    for (int i = 0; i < 10; i++)
    {
        ((t_data *)data)->state += 1;
        printf("state: %d\n", ((t_data *)data)->state);
        usleep(100);
    }
    //========= critical section ============
    pthread_mutex_unlock(&((t_data *)data)->mutex);
    return ((void *)data);
}

int main()
{
    t_data      data;
    pthread_t	thread1,thread2;
	int			status1;
    int         status2;

    data.state = 0;
    pthread_mutex_init(&data.mutex, NULL);

    pthread_create(&thread1, NULL, count, (void *)&data);
    pthread_create(&thread2, NULL, count, (void *)&data);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&data.mutex);
}