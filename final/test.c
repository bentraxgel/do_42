// #include "get_next_line.h"
#include <stdio.h>

char *change_value(void)
{
	char	new;

	new = 'a';
	return (&new);
}

int main(void)
{
	char	*c;

	c = change_value();
	*c = 'c';
	
	return (0);
}
