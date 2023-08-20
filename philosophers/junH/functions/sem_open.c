#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>


/*
	세마포어를 초기화하고 여는 함수이다.

	sem_t *sem_open(const char *name, int oflag, ...);
*/

int		num = 2;
sem_t	*semaphore;

void	*routine(void *arg)
{
	printf("%d\n", num);
	if (num > 0)
	{
		num -= 1;
		sem_wait(semaphore); // lock 포크 집기
	}
	else
	{
		while (num == 0) {}
		sem_post(semaphore); // unlock 포크 내려놓기
		num += 1;
	}
	return (arg);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	// S_IRUSR: read permission, owner
	// S_IWUSR: write permission, owner
	semaphore = sem_open("hello", O_CREAT, S_IRUSR | S_IWUSR, 1); 
	pthread_create(&thread1, NULL, routine, NULL);
	pthread_create(&thread2, NULL, routine, NULL);
	sem_unlink("hello");
	return (0);
}
