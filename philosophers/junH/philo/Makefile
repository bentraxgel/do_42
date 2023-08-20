# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 10:28:24 by joonhan           #+#    #+#              #
#    Updated: 2022/11/08 10:08:22 by joonhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:=	philo

SRC_FILES		:=	main.c				\
					main_utils.c		\
					ft_atoi.c			\
					init_data.c			\
					create_philos.c		\
					routine.c			\
					routine_utils.c		\
					fork.c				\
					monitoring.c		\
					free_all.c
SRC_OBJS		:=	$(SRC_FILES:%.c=%.o)

CC 				:=	gcc
CFLAGS 			:=	-Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	rm -f $(SRC_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(SRC_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@