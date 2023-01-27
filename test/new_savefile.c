#include "header.h"

int	ft_strlen(char const *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sstart;
	size_t	i;
	size_t	s_len;

	i = 0;
	sstart = (size_t)start;
	s_len = ft_strlen(s);
	if (s_len <= sstart)
		return ("fail");
	if (s_len - start <= len)
		str = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (s_len - start > len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[sstart + i] && i < len)
	{
		str[i] = s[sstart + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*my_new_save(char *save, int find) //save = new((save - ret))
{
	int	count;

	count = 0;
	while (save[find + count])
		count++;
	if(count)
		return (ft_substr(save, find, count));
	return (save);
}

int	main()
{
	char	*ret = "1234567890";
	ret = my_new_save("hello", 2);
	printf("ret : %s\n", my_new_save("hello", 2));
	for (int i = 0; i < 6; i++)
	{
		printf("%c ", ret[i]);
	}
	return (0);
}