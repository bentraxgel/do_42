#include <stdio.h>
#include "../libft/libft.h"
#include "../push_swap.h"

void	leaks()
{
	system("leaks -q a.out");
}

int	exception(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while(str[i])
		ret += ft_isdigit(str[i++]);
	return (ret);
}

int	main(int argc, char *argv[])
{
	atexit(leaks); //TODO del
	size_t	i;
	char	*arg;
	char	*space;
	char	**word;
	// t_stack	stack;

	i = 0;
	space = " ";
	if (argc == 1)
		return (0);
	while (argv[++i])
	{
		if (exception(argv[i]) != 0)
		{
			arg = ft_strjoin_free(arg, argv[i]);
			arg = ft_strjoin_free(arg, space);
		}
		else
		{
			free(arg);
			my_error();
		}
	}
	word = ft_split(arg, ' ');
	free(arg);

	i = 0;
	while (word[i]){
		printf("word[%zu] : %s\n", i, word[i]);
		i++;
	}
	for (int i = 0; word[i]; i++)
		free(word[i]);
	free(word);
}