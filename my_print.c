#include "printf.h"
#include <stdio.h>
int	my_va_int(char ch, long long num)
 {
	char	*str;
	int		len;

	str = 0;
	if (ch == 'c')
	{
		ft_putchar_fd(num, 1);
		return (1);
	}
	else if (ch == 'd' || ch == 'i')
		str = ft_itoa(num);
	else if (ch == 'u')
		str = ft_itoa_unsign(num);
	else if (ch == 'x' || ch == 'X')
		str = ft_itoa_hex(num, ch);
	len = my_print(str);
	free(str);
	return (len);
 }

int	my_va_void(void *str)
{
	int	len;

	str = ft_itoa_hex_long((unsigned long long)str);
	write(1, "0x", 2);
	len = my_print(str) + 2;
	free(str);
	return (len);
}

int	my_print(char *str)
{
	int		len;

	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}