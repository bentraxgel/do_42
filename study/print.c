#include <stdio.h>

int is(int n)
{
	int e = 8;
	if (e > n){
		printf("IF\n");
		return (n - e) ==  2;
		}
	else{
		printf("ELSE\n");
		return (e + 1) == 7;
	}
}

int	main()
{
	printf("%d\n", is(10));
}
