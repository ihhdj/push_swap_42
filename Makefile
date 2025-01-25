# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 12:09:38 by ihhadjal          #+#    #+#              #
#    Updated: 2025/01/25 12:27:27 by iheb             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN	= \033[0;32m
RED		= \033[0;31m
ORANGE	= \033[0;33m
BLUE	= \033[0;34m
CYAN	= \033[0;36m
BOLD	= \033[1m
RESET	= \033[0m

CHECK	= $(GREEN)✓$(RESET)
CROSS	= $(RED)✗$(RESET)
GEAR	= $(ORANGE)⚙️$(RESET)
TRASH	= $(ORANGE)🗑️$(RESET)
ROCKET	= $(BLUE)🚀$(RESET)
BAR		= $(CYAN)█$(RESET)

SRCS	= code/main.c code/parsing.c code/utils.c code/stack.c code/instructions.c
OBJS	= ${SRCS:.c=.o}
NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
RM		= rm -rf
LIBFT	= ./resources/libft
TOTAL	= $(words $(SRCS))
PROGRESS_FILE = .make_progress


define progress_bar
@if [ ! -f $(PROGRESS_FILE) ]; then echo 0 > $(PROGRESS_FILE); fi
@current=$$(cat $(PROGRESS_FILE)); \
new=$$(($$current + 1)); \
echo $$new > $(PROGRESS_FILE); \
percent=$$(($$new * 100 / $(TOTAL))); \
filled=$$(($$percent / 2)); \
remaining=$$((50 - $$filled)); \
printf "\r[$(BOLD)$(CYAN)"; \
printf "█%.0s" $$(seq 1 $$filled); \
printf "░%.0s" $$(seq 1 $$remaining); \
printf "$(RESET)] $(BOLD)%3d%%$(RESET) Compiling $(CYAN)$(BOLD)%s$(RESET)" $$percent "$<"; \
$(CC) $(CFLAGS) -c -o $@ $< 2> /dev/null; \
if [ $$? -eq 0 ]; then \
	printf " $(CHECK)\n"; \
else \
	printf " $(CROSS)\n"; \
	exit 1; \
fi
endef

all: init_progress ${NAME}
	@echo "\n$(ROCKET) $(BOLD)$(GREEN)Push_swap ready!$(RESET) $(ROCKET)"
	@$(RM) $(PROGRESS_FILE)

init_progress:
	@echo 0 > $(PROGRESS_FILE)

${NAME}: ${OBJS}
	@printf "$(GEAR) Building Libft..."
	@${MAKE} -C ${LIBFT} > /dev/null 2>&1 && echo "\r$(CHECK) Libft built!" || { echo "\r$(CROSS) Libft build failed!"; exit 1; }
	@printf "$(GEAR) Linking $@..."
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a > /dev/null 2>&1 && echo "\r$(CHECK) Linking complete!" || { echo "\r$(CROSS) Linking failed!"; exit 1; }

%.o: %.c
	$(progress_bar)

clean:
	@printf "$(TRASH) Cleaning objects..."
	@${MAKE} clean -C ${LIBFT} > /dev/null 2>&1
	@${RM} ${OBJS} $(PROGRESS_FILE) > /dev/null 2>&1 && echo "\r$(CHECK) Objects cleaned!" || { echo "\r$(CROSS) Clean failed!"; exit 1; }

fclean: clean
	@printf "$(TRASH) Full clean..."
	@${RM} ${NAME} > /dev/null 2>&1
	@${RM} ${LIBFT}/libft.a > /dev/null 2>&1 && echo "\r$(CHECK) Full clean complete!" || { echo "\r$(CROSS) Full clean failed!"; exit 1; }

re: fclean all
	@echo "$(BOLD)$(BLUE)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re init_progress