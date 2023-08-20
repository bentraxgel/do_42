NAME 	= philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

# NOTE: Add files
# ================================================
SRC 								= check_arg \
									  ft_itoa \
									  ft_atoi \
									  init_data \
									  monitor \
									  philo_action \
									  philosophers \
									  utils \
# ================================================

SRC_CUR = $(addsuffix .c, $(SRC))
OBJ = $(SRC_CUR:.c=.o)
HEAD 	= philosophers.h
# NOTE: my tools
# ============================================
Black	=\033[0;30m
Red		=\033[1;31m
Green	=\033[0;32m
Yellow	=\033[0;33m
Blue	=\033[0;34m
Purple	=\033[0;35m
Gray    = \033[0;90m
Cyan	=\033[0;36m
White	=\033[1;37m
DEF_COLOR = \033[0;39m
LF = \e[1K\r
TOTAL_FILES = $(words $(SRC_CUR))
CURRENT_FILE = 1
# ============================================

progress_bar = printf "$(LF)$(Red)[ ♔Compiling...♔ ]$(DEF_COLOR) $(Cyan)[$(1)/$(2)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $(shell echo "scale=1; ($(1) / $(2)) * 100" | bc); \
		printf " $(White)[%-*s%s]$(DEF_COLOR)" 25 "$(shell printf '%0.*s' $$(($(1) * 25 / $(2))) '=========================================================================')>" ""; \
		printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(Cyan)Compiling... $< $(DEF_COLOR) \033[A\033[999C\e[?25l" \
		sleep 1

all : $(NAME)

$(NAME) : $(OBJ) $(HEAD)
	@$(CC) $(CFLAGS) -I $(HEAD) $(OBJ) -o $(NAME)
	@printf "$(LF)"
	@printf "\n\033[1;32m✅ Compilation complete. $(NAME) has been created. ✅\033[0m\n\n\e[?25h"

ifdef BONUS
	@echo "$(Green)=====================================================$(DEF_COLOR)"
	@echo "$(Green)|     🎉  philosophers bonus compile succsess.  🎉   |$(DEF_COLOR)"
	@echo "$(Green)=====================================================$(DEF_COLOR)"
else
	@echo "$(Green)===============================================$(DEF_COLOR)"
	@echo "$(Green)|  🥳  philosophers compile succsess. 🥳       |$(DEF_COLOR)"
	@echo "$(Green)===============================================$(DEF_COLOR)"
endif


.c.o : 
	@$(CC) $(CFLAGS) -I $(HEAD) -c -o $@ $<
	@$(call progress_bar,$(CURRENT_FILE),$(TOTAL_FILES))
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@sleep 0.1


clean :
	@rm -rf *.o
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(Purple)libft$(White) $(OBJ) $(DEF_COLOR)\n"

fclean : clean
	@rm -rf $(NAME)
	@echo "\n🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@echo "$(Cyan)Clearing terminal in [3seconds]...$(DEFAULT_COLOR)"
	@sleep 1
	@clear

re : fclean
	@sleep 0.5
	@clear
	@printf "$(Purple)♻️ REBUILD ♻️\n\n"
	@$(MAKE) all

bonus :
	@make $(NAME)

.PHONY : all re clean fclean bonus


