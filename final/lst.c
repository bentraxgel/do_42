#include "lst.h"

t_list	*my_lst_find(t_list **lst, int f_fd)
{
	t_list	*temp;

	if ((*lst) == 0)
	{
		//(*lst) = malloc(sizeof(t_list));
		(*lst)->fd = f_fd;
		(*lst)->next = NULL;
		(*lst)->save = "first meet";
		return ((*lst));
	}
	// if (*lst == 0)
	// {
	// 	temp = malloc(sizeof(t_list));
	// 	temp->fd = f_fd;
	// 	temp->next = NULL;
	// 	temp->save = "first meet";
	// 	*lst = temp;
	// 	return (temp);
	// }
	temp = *lst;
	while (temp)
	{
		if (temp->fd == f_fd)
		{
			temp->save = "find fd";
			return (temp);
		}
		temp = temp->next;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	temp = malloc(sizeof(t_list));
	(*lst)->next = temp;
	temp->next = NULL;
	temp->fd = f_fd;
	temp->save = "new node";
	return (temp);
}

// char	*get_next_line(int fd)
// {

// 	static t_list	*lst;
// 	t_list			*find;

// 	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
// 		return (0);
// 	//printf("before : %s, %p",lst->save, lst);
// 	find = my_lst_find(lst, fd);
// 	// printf("save : %s\n", find->save);
// 	printf("before : %d, %p\n",lst->fd, lst);
// 	return (lst->save);
// } 

// int	main()
// {
// 	int	fd;
// 	char	*str;q

// 	fd = open("text.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("lst->save : %s\n", str);
// 	close(fd);
// }

int	main()
{
	static t_list	*lst;
	t_list			*find;
	int				fd;

	fd = open("text.txt", O_RDONLY);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	//printf("before : %s, %p",lst->save, lst);
	printf("\n\nfd : %d\n", fd);
	for (int i = 0; i < 3; i++)
	{
		find = my_lst_find(&lst, fd);
		// printf("save : %s\n", find->save);
		printf("fd, lst_ADR : %d, %p\n",lst->fd, lst);
		printf("find_fd, lst_ADR : %d, %p\n",find->fd, lst);
		printf("save : %s\n", lst->save);
		printf("find_save : %s\n\n", find->save);
	}
	fd = open("text.txt", O_RDWR);
	printf("\n\nfd : %d\n", fd);
	find = my_lst_find(&lst, fd);
	// printf("save : %s\n", find->save);
	printf("fd, lst_ADR : %d, %p\n",lst->fd, lst);
	printf("find_fd, lst_ADR : %d, %p\n",find->fd, lst);
	printf("save : %s\n", lst->save);
	printf("find_save : %s\n", find->save);
}