NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread
SRCS = main.c check_arg.c init.c fork.c philo.c utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I. $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
