NAME = philo

HEADER = philo.h

SRCS = philo.c \
		philo_utils.c \
		philo_utils2.c \
		what_philos_do.c \
		what_philos_do2.c \
		various_init_func.c \
		monitor.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=thread -g3

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re