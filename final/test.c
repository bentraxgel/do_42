#include "get_next_line.h"

int change_value(t_list *lst)
{
	lst->save = ft_strdup("12345");
	return (0);
}

int main(void)
{
	static t_list *lst;
	t_list new;
	
	lst = &new;
	change_value(lst);
	printf("%s\n", lst->save);
	
	return (0);
}
