/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:59:31 by seok              #+#    #+#             */
/*   Updated: 2023/02/22 11:27:45 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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

size_t	ft_strlen(const char *s);
void	my_lst_free(t_list *find, t_list *head);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
t_list	*my_lst_make(t_list **head);
t_list	*my_lst_find(t_list **head, int f_fd);
int		my_save_buf(t_list *find, char **ret, int check);
char	*my_save_check(int fd, t_list **head);
char	*get_next_line(int fd);

#endif