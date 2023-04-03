// #include <stdio.h>

// int	main()
// {
// 	printf("%d", printf("%-9.7d", 12345));
// }

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list ap;
	
	va_start(ap, format);
	printf ("va_start : %p\n", ap);
	// while (*format)
	for (int i = 0; i < 3; i++)
	{
		printf("%c\n", va_arg(ap, int));
		//format += sizeof(char);
	}
	va_end(ap);
	//return (num);
	return 0;
}

int	main()
{
	ft_printf("abc", 'a', 97);
    printf("\nprintf : %.0s++", "123");
    printf("\nprintf : %.1d++\n", 123);
}