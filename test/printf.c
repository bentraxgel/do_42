#include <stdio.h>
#include <unistd.h>

int	main()
{
	printf("print\n %s", "abc");
	write(1, "ABC\n", 4);
	printf("개행%s\n%s", "점프", "top");
	printf("\n\nerror test : %d\n", printf(""));
	return (0);
}