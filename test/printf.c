#include <stdio.h>
#include <unistd.h>

void	func(char ch)
{
	printf("\n\tFUNC : %c\n", ch);
}

int	main()
{
	const char *format = "12345";
	int	n = 3;
	char c = 'A';
	int	len;

	printf("C : %c\n", 3);
	printf("C : %d\n", c);
	// write(1, n + '0', 1);
	printf("print\n %s", "abc");
	printf("개행%s\n%s", "점프", "top");
	len = write(1, "ABC\n", 4);
	len = write(1, "ABC\n", 4);
	printf("\n\nerror test : %d\n", printf(""));
	// printf("NOT : %k");
	func(format[3]);
	printf("\nlen : %d\n", len);
	return (0);
}