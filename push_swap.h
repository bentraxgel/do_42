/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:37 by seok              #+#    #+#             */
/*   Updated: 2023/05/29 19:39:13 by seok             ###   ########.fr       */
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

typedef enum e_cmd
{
	RA = 0,
	RB,
	RRA,
	RRB,
	PA,
	PB,
	SA,
	SB,
} t_cmd;

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
	int	p0;
	int	p1;
	int p2;
	int ra; //TODO size_t로 변환
	int	rb;
	int	pa;
	int	pb;
	int	a;
	int	b;
	int	num;
	int a_sort; //TODO del
	int	b_sort;
} t_info;

//main.c
int	exception(char *str);


//main_utill.c
int		my_error();
	//두개가 따로 필요한 이유는? : 없는거같은디
void	a_stack_indexing(t_stack *stack, size_t start, size_t len);
void	b_stack_indexing(t_stack *stack, size_t start, size_t len);
int		a_sort_check(int *arr, size_t len);
int		b_sort_check(int *arr, size_t len);
int		duplicate_check(int *arr, size_t len);

//command.c
int		command(t_cmd cmd, t_stack *stack, t_info *info);
void	r_command(t_stack *stack, t_info *info, t_set flag, size_t top);
void	rr_command(t_stack *stack, t_set flag, size_t top);
void	p_command(t_stack *stack, t_info *info, t_set flag);
void	s_command(t_stack *stack, t_set flag);

//print.c
t_list	*r_print(t_list *command);
t_list	*rr_print(t_list *command);
t_list	*s_print(t_list *command);
void	print_command(t_list *command);

//TODO 노미넷 여기부터
//pivot.c //하기싫어ㅓㅓㅓㅓ
void	save_pivot(t_stack *stack, t_info *info, t_set flag, size_t num);
void	mini_pivot(t_stack *stack, t_info *info, t_set flag, size_t num);
void	reset_info(t_info *info);

//sort_stack.c
void	a_stack_sort(t_stack *stack, size_t num, t_info *info);
void	b_stack_sort(t_stack *stack, size_t num, t_info *info);
void	sort_rr(t_stack *stack, t_info *info);
void	mini_sort(t_stack *stack, t_info *info, size_t num, t_set flag);
void	hard_sort(t_stack *stack, t_info *info, size_t num, t_set flag);

//sort_utill.c
void	two_sort(t_stack *stack, t_set flag, t_info *info);
void	hard_a_only(t_stack *stack, t_info *info, size_t num);
void	hard_a_another(t_stack *stack, t_info *info, size_t num);
void	hard_b_only(t_stack *stack, t_info *info, size_t num);
void	hard_b_another(t_stack *stack, t_info *info, size_t num);

	//TODO del file
void quickSort(int data[], int start, int end);
int getPivot(int data[], int start, int end);

//TODO 노미넷 여기까지

//sort_three.c
void	a_three_only(t_stack *stack, t_info *info, size_t top);
void	a_three_another(t_stack *stack, t_info *info, size_t top);
void	b_three_only(t_stack *stack, t_info *info, size_t top);
void	b_three_another(t_stack *stack, t_info *info, size_t top);

//sort_a_case.c
void	a_first_case(t_stack *stack, t_info *info);
void	a_second_case(t_stack *stack, t_info *info);
void	a_third_case(t_stack *stack, t_info *info);
void	a_fourth_case(t_stack *stack, t_info *info);
void	a_fifth_case(t_stack *stack, t_info *info);

//sort_b_case.c
void	b_first_case(t_stack *stack, t_info *info);
void	b_second_case(t_stack *stack, t_info *info);
void	b_third_case(t_stack *stack, t_info *info);
void	b_fourth_case(t_stack *stack, t_info *info);
void	b_fifth_case(t_stack *stack, t_info *info);

//ft_atoi_pro.c
int		ft_isspace_pro(int c);
void	my_check_digit(const char *str);
void	my_check_limit(long long num);
int		ft_atoi_pro(const char *str);

#endif
