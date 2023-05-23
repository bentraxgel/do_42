#include <unistd.h>
#include <stdio.h>

 int	main(int ac, char *av[2])
 {
	int i;
	int j;
	int no, no2;
	char *a1 = av[1];
	char *a2 = av[2];
	printf("a1 : %p\n", a1);
	printf("a2 : %p\n", a2);
	char	target;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (a1[0] != 0)
	{
		write(1, &a1[0], 1);
		i = 1;
		/* 
			만약 a1이 빈문자열이라면 i = 0이어야함. 빈공간에 어떤값이 들어가있을지 모르니깐
			그동안 a1랑 a2이 바로 붙어있게 메모리 할당을 받았기때문에 a1이 빈문자열일때
			i = 1이므로 a2[0]을 읽어서 a2의 값을 읽었기때문에 두번 출력됐던것! - 해결완료?!?!
		*/
	}
	i = 1;
	while (a1[i] != 0)
	{
		printf("show a1\n");
		target = a1[i];
		j = 0;
		no = 0;
		while (j < i)
		{
			if (a1[j] == target)
				no = 1;
			j++;
		}
		if (no == 0)
			write(1, &a1[i], 1);
		i++;
	}
	i = 0;
	while (a2[i] != 0)
	{
		printf("show a2\n");
		target = a2[i];
		no = 0;
		j = 0;
		while (a1[j] != 0)
		{
			if (target == a1[j])
				no = 1;
			j++;
		}
		j = 0;
		no2 = 0;
		while (j < i)
		{
			if (target == a2[j])
				no2 = 1;
			j++;
		}
		if (no == 0 && no2 == 0)
			write(1, &target, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
 }