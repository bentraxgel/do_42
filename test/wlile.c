#include "printf.h"

int	func()
{
	int	n = 10;
	return (n);
}

int	main()
{
	char	*p = "0123456789";
	char	*q = "12345";
	int		i = -1;
	int		d = -1;
	int		len = 0;
	
	while (p[++i])
	{
		if (p[i] == '3')
		{
			d = -1;
			while (q[++d])
			{
				if (p[i + 1] == q[d])
				{
					printf("d : %d\n", d);
					// if (q[d] == '4')
					// {
					// 	printf("d : %d\n", d);
					// 	printf("4\n");
					// 	i++;
					// 	len += func();
					// 	// break ;
					// }
					// else if (p[i] == '4')
					// {
					// 	printf("d : %d\n", d);
					// 	printf("else if\n");
					// 	// break ;
					// }
					// else if (1)
					// 	printf("no\n");

				}
				else
					printf("else\n");
			}
		}
		else
			printf("<i %d> <p %c>\n", i, p[i]);
	}
	printf("len : %d", len);
}