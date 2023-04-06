#include <stdio.h>
#include <stdlib.h>

int main()
{
	int d_num;
	int i_num;
	char *str;
	int	idx = 4;

	str = malloc(sizeof(idx));
	str = "123456789";
	printf("str : %s\n", str);
	// printf("idx_size : %lu\n", sizeof(idx));
	// printf("str_size : %lu\n", sizeof(str));
	scanf("%d", &d_num); //011을 입력하면 11로 인식
	scanf("%i", &i_num); //011을 입력하면 9로 인식
	printf("deciaml\n");
	printf("%d\n", d_num);
	printf("%d", i_num);
	printf("\ninteger\n");
	printf("%i\n", d_num);
	printf("%i", i_num);
	printf("\nsizeof : %lu", sizeof(d_num));
}