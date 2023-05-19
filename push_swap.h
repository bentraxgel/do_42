/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:37 by seok              #+#    #+#             */
/*   Updated: 2023/05/20 05:40:25 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

# define TRUE 1
# define FALSE 0
typedef enum e_set
{
	STACK_A = 0,
	STACK_B,
}t_set;

typedef struct s_stack
{
	t_list		*command;
	int			*a;
	int			*b;
	int			*total; //이자식 없어도 될것같은데
	size_t	a_len;
	size_t	b_len;
	size_t	total_len;
} t_stack;

typedef struct s_info
{
	int	p1;
	int p2;
	int ra;
	int	rb;
	int	pa;
	int	pb;
} t_info;

//main_utill.c
int		my_error();
void	a_stack_indexing(t_stack *stack, int start, int len);
void	b_stack_indexing(t_stack *stack, int start, int len);
int		sort_check(int *arr, size_t len);
int		duplicate_check(int *arr, size_t len);

//command.c
void	r_command(t_stack *stack, int flag, size_t len);
void	rr_command(t_stack *stack, int flag, size_t len);
void	p_command(t_stack *stack, int flag);
void	s_command(t_stack *stack, int flag);

//print.c
t_list	*r_print(t_list *command);
t_list	*rr_print(t_list *command);
t_list	*s_print(t_list *command);
void	print_command(t_list *command);

//sort.c
void	a_stack_sort(t_stack *stack, int num);
void	b_stack_sort(t_stack *stack, int num, t_info *info);

//sort_hard.c
void	hard_sort(int len, int flag, t_stack *stack);
void	two_sort(t_stack *stack, int flag, int idx);

//sort_utill.c
void	my_pivot(int start, int len, t_info *info);
void	two_sort(t_stack *stack, int flag, int idx);

//ft_atoi_pro.c
int		ft_isspace_pro(int c);
void	my_check_digit(const char *str);
void	my_check_limit(long long num);
int		ft_atoi_pro(const char *str);

#endif
