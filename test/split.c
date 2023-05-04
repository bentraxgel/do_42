#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main()
{
	char *str = "test hello world";
	char	**word;

	word = ft_split(str, ' ');
	for (int i = 0; word[i]; i++)
		printf("word[%d] : %s\n", i, word[i]);
}