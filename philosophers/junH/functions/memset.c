#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	buf[10];
	int		arr[10];

	// char형 배열
	memset(buf, 'a', 9);
	buf[9] = '\0';
	printf("%s\n", buf);
	// int형 배열
	// 초기화 값을 0이 아닌 다른 값을 넣으면 예상할 수 없는 값이 저장됨
	// memset은 1바이트 단위로 값을 초기화 하기 때문에 4바이트 int 자료형은 0이 아니면 제대로 저장되지 않는다.
	memset(arr, 0, 10 * sizeof(int));
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
}