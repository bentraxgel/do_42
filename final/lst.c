#include "lst.h"

t_list	*my_lst_find1(t_list *lst, int f_fd, int check)
{
	t_list	*temp;
	
	printf("lst : %p\n", lst);
	printf("&lst : %p\n", &lst);
	if (check != 0)
	{
		lst = malloc(sizeof(t_list));
		lst->fd = f_fd;
		lst->next = NULL;
		lst->save = "first meet";
		return (lst);
	}
	else if (check == 0)
	{
		// temp = malloc(sizeof(t_list));
		// lst = temp;
		lst->save = "test";
		return (lst);
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
	temp = lst;
	while (temp->next)
	{
		if (temp->fd == f_fd)
		{
			temp->save = "find fd";
			return (temp);
		}
		temp = temp->next;
	}
	while (lst->next)
		lst = lst->next;
	temp = malloc(sizeof(t_list));
	lst->next = temp;
	temp->next = NULL;
	temp->fd = f_fd;
	temp->save = "new node";
	return (temp);
}

t_list	*my_lst_find(t_list **lst, int f_fd)
{
	t_list	*temp;
	
	// printf("**lst : %s\n", *lst);
	printf("*lst : %p\n", *lst);
	printf("lst : %p\n", lst);
	// if ((*lst) == 0)
	// {
	// 	(*lst) = malloc(sizeof(t_list));
	// 	(*lst)->fd = f_fd;
	// 	(*lst)->next = NULL;
	// 	(*lst)->save = "first meet";
	// 	return ((*lst));
	// }
	if (*lst == 0)
	{
		temp = malloc(sizeof(t_list));
		temp->fd = f_fd;
		temp->next = NULL;
		temp->save = "first meet";
		*lst = temp;
		printf("*lst : %p\n", *lst);
		printf("lst : %p\n", lst);
		return (temp);
	}
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
	static t_list	list;

	printf("main_liste : %p\n", &list);
	// list = malloc(sizeof(t_list));
	list.save = "list save first value";
	printf("list->save : %s\n", list.save);

	// printf("main_*lst : %p\n", *lst);
	printf("main_list malloc: %p\n", &list);

	fd = open("text.txt", O_RDONLY);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	//printf("before : %s, %p",lst->save, lst);
	printf("\n\nfd : %d\n", fd);
	for (int i = 0; i < 3; i++)
	{
		printf("before list : %s\n", list.save);
		find = my_lst_find1(&list, fd, 1);
		printf("====test====\n");
		printf("list : %p\n", &list);
		printf("find : %p\n", find);
		printf("after list : %s\n", list.save);
		printf("after find : %s\n", find->save);
		// find = my_lst_find1(&list, fd, 8);
		printf("====test2====\n");
		printf("list : %p\n", &list);
		printf("find : %p\n", find);
		printf("after list : %s\n", list.save);
		printf("after find : %s\n", find->save);
		// find = my_lst_find(&lst, fd);
		// printf("save : %s\n", find->save);
		printf("fd, lst_ADR : %d, %p\n",lst->fd, lst);
		printf("find_fd, find_ADR : %d, %p\n",find->fd, find);
		printf("save : %s\n", lst->save);
		printf("find_save : %s\n\n", find->save);
	}
	fd = open("text.txt", O_RDWR);
	printf("\n\nfd : %d\n", fd);
	find = my_lst_find1(&list, fd, 0);
	// find = my_lst_find(&lst, fd);
	// printf("save : %s\n", find->save);
	printf("fd, lst_ADR : %d, %p\n",lst->fd, lst);
	printf("find_fd, find_ADR : %d, %p\n",find->fd, find);
	printf("save : %s\n", lst->save);
	printf("find_save : %s\n", find->save);
}