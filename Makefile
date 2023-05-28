CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
NAME = push_swap
INCD = push_swap.h
SRCD = .c\
OBJS = $(SRCD:.c=.o)
$(NAME) : $(OBJS)
	make -C ./libft all
	cp ./libft/libft.a ./$(NAME)
	ar $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)
clBean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re