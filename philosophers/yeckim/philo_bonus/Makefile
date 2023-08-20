NAME = philo_bonus
CC = cc
FLAG = -Wall -Wextra -Werror
SRCS = $(wildcard ./src_bonus/*.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAG) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAG) -o $@ $^

bonus : $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: bonus re all clean fclean
