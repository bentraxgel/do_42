#include <stdio.h>

int	main()
{
	printf("%u\n", (unsigned int)2147483648); //max + 1

	printf("%d\n", (int)2147483647); //max
	printf("%d\n", (int)2147483648); // min
}