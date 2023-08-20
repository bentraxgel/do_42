# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 10:28:24 by joonhan           #+#    #+#              #
#    Updated: 2022/11/11 14:56:52 by joonhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:=	philo_bonus

SRC_FILES		:=	main				\
					main_utils			\
					ft_atoi				\
					init_data			\
					clear_data			\
					create_philos		\
					clear_data			\
					monitor				\
					routine				\
					routine_utils
SRCS			:=	$(addsuffix .c, $(addsuffix _bonus, $(SRC_FILES)))
SRC_OBJS		:=	$(SRCS:%.c=%.o)

CC 				:=	gcc
CFLAGS 			:=	-Wall -Wextra -Werror -g

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	rm -f $(SRC_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : all

$(NAME) : $(SRC_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@