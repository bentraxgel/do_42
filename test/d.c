#include <stdio.h>

int	main()
{
	int	j = 0;
	int	arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	int i = -1;
	while (++i < 5)
		printf("%d", arr[j++]);
	printf("\n i : %d\n", i);
	while (i++ < 7)
		printf("%d ", arr[j++]);
	printf("\n");
}