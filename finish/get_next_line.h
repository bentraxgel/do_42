/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:59:31 by seok              #+#    #+#             */
/*   Updated: 2023/02/18 02:47:12 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

size_t	ft_strlen(const char *s);
void	*ft_memset(void *str, int value, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
t_list	*my_lst_find(t_list **head, int f_fd);
void	my_lst_free(t_list *find, t_list *head);
void	my_check_zero(t_list *head, t_list *find, int check, char **ret);
char	*my_save_buf(t_list *find, t_list *head, char *ret);
char	*get_next_line(int fd);

#endif