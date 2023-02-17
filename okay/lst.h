#ifndef LST_H
# define LST_H

/*	test	*/
#include <fcntl.h> //open
#include <stdio.h> //printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	char			*save;
	struct s_list	*next;
}t_list;

# endif