	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

struct s_type
{
	int	i;
	char	*str;
}s, *p;

typedef struct s_pe
{
	int	j;
	char	*bar;
}ty;

struct test
{
	int	i;
	char	str[80];
}test = {2, "test!"};

 int	main()
 {
	printf("test : %d, %s\n", test.i, test.str);
	struct s_type	num;
	num.i = 1;
	printf("num : %d\n", num.i);
	num.str = malloc(100);
	strcpy(num.str, "홍길동");
	printf("strcpy : %s\n", num.str);
	// num.str = "gildong";
	// printf("strcpy : %s\n", num.str);
	ty	to;
	to.j = 6;
	printf("to : %d\n", to.j);
	ty	*ptr;
	ptr = malloc(sizeof(ty));
	ptr->j = 5;
	printf("ptr : %d\n", ptr->j);
	(*ptr).j = 10;
	printf("ptr : %d\n", ptr->j);
	ptr->bar = "a";

	// printf("num.i : %d\n", num.i);
	// printf("*p : %d", p->i);
	// printf("do\n");

	p = malloc(sizeof(struct s_type));
	p->i = 1;
//	printf("s.i : %d\n", s.i);
	printf("p->i : %d\n", p->i);

	struct s_type	*test;
	test = malloc(sizeof(struct s_type));
	test->i = 7;
	printf("test->i : %d\n", test->i);

	s.i = 10;
	printf("s.i : %d\n", s.i);
	// printf("s_ADR : %p\n", s);
	// printf("*p_ADR : %p\n", *p);
	// printf("p_ADR : %p\n", p);
	// printf("&p_ADR : %p\n", &p);
	
 }