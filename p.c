#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_print(const char *format, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, format);
	str = malloc(sizeof(char) * 100);
	// str = &ap;
	// printf("ap : %s\n", str);
	// str = va_start(ap, format);
	// printf("start_str : $s\n", str);
	printf("p : %p\n", str);
	printf("d : %llu\n", (unsigned long long)str);
	str = va_arg(ap, char *);// (char *) 포인터는 8byte
	unsigned long long address;
	address = (unsigned long long)str; //변형하면 숫자(->주소?)
	printf("adress : %llu\n\n", address);
	// (int)str -> 10진법
	// 10진법 -> 16진법?
	printf("arg_str : %llu\n", (unsigned long long)str);
	printf("p : %p\n", str);
	return (0);

	// str = "hello";// 0x123
	// str = "tell";//0x234
}

int	main()
{
	ft_print("t", "hello");
}