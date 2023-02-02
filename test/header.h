#ifndef	HEADER_H
# define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SISE
# define BUFFER_SIZE 0
#endif

typedef struct s_list
{
	char			*buf;
	int				fd;
	char			*save;
	struct s_list	*next;
}t_list ;

#endif
