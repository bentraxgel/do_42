#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

char	*hex(unsigned long long add)
{
	
}

int	ft_print(const char *format, ...)
{
	va_list	ap;
	char	*str;
	unsigned long long address;

	va_start(ap, format);

	str = malloc(sizeof(char) * 100);
	printf("str_%%p : %p\n", str);
	printf("str_%%llu : %llu\n\n", (unsigned long long)str);

	str = va_arg(ap, char *);// (char *) 포인터는 8byte
	address = (unsigned long long)str; //정수형으로 형변환
	printf("address : %llu\n", address);
	printf("arg_str : %llu\n", (unsigned long long)str);
	// (강제형변환)str -> 10진법
	// 10진법 -> (0x +) 16진법
	printf("str_%%p : %p\n", str);
	return (0);

	// str = "hello";// 0x123
	// str = "tell";//0x234
	//즉 문자열이 들어있는 주소자체를 값으로 주는거기 때문에 주소가 바뀌는것.
	//char *형이기때문에 주소를 값으로 갖는다.
}

int	main()
{
	ft_print("t", "hello");
}