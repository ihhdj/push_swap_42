# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 12:09:38 by ihhadjal          #+#    #+#              #
#    Updated: 2025/01/28 11:12:07 by deniayoubov      ###   ########.fr        #
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

SRCS	= code/main.c code/parsing.c code/utils.c code/stack.c code/swap.c
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
@current=$$(($$(cat $(PROGRESS_FILE)) + 1)); \
echo $$current > $(PROGRESS_FILE); \
percent=$$(($$current * 100 / $(TOTAL))); \
filled=$$(($$percent * 20 / 100)); \
remaining=$$((20 - $$filled)); \
bar=""; \
for i in $$(seq 1 $$filled); do bar="$${bar}█"; done; \
for i in $$(seq 1 $$remaining); do bar="$${bar}▁"; done; \
printf "\r[$(CYAN)$${bar}$(RESET)] $(BOLD)%3d%%$(RESET) Compilation globale..." $$percent; \
if ! ${CC} ${CFLAGS} -c -o $@ $< 2>&1; then \
    printf "\n\n$(RED)――――――――――――――――――――――――――――――――――――――――――――――――$(RESET)\n"; \
    printf "$(RED)✗ ERREUR DE COMPILATION dans $(BOLD)$<$(RESET)\n\n"; \
    ${CC} ${CFLAGS} -c -o $@ $<; \
    printf "\n$(RED)――――――――――――――――――――――――――――――――――――――――――――――――$(RESET)\n"; \
    $(RM) $(PROGRESS_FILE); \
    exit 1; \
fi; \
if [ $$current -eq $(TOTAL) ]; then \
    printf "\r[$(RED)####################$(RESET)] $(BOLD)100%%$(RESET) Compilation terminée!  \n"; \
fi
endef

all: init_progress ${NAME}
	@echo "\n$(ROCKET) $(BOLD)$(RED)Push_swap prêt !$(RESET) $(ROCKET)"
	@$(RM) $(PROGRESS_FILE)

init_progress:
	@echo 0 > $(PROGRESS_FILE)

${NAME}: ${OBJS}
	@${MAKE} -C ${LIBFT} > /dev/null 2>&1 && echo "\r$(CHECK) Libft construite!" || { echo "\r$(CROSS) Échec de Libft!"; exit 1; }
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a > /dev/null 2>&1 && echo "\r$(CHECK) Liens complétés!" || { echo "\r$(CROSS) Échec des liens !"; exit 1; }

%.o: %.c
	$(progress_bar)

clean:
	@printf "$(TRASH) Nettoyage..."
	@${MAKE} clean -C ${LIBFT} > /dev/null 2>&1
	@${RM} ${OBJS} $(PROGRESS_FILE) > /dev/null 2>&1 && echo "\r$(CHECK) Nettoyage réussi !" || { echo "\r$(CROSS) Échec du nettoyage !"; exit 1; }

fclean: clean
	@printf "$(TRASH) Nettoyage complet..."
	@${RM} ${NAME} > /dev/null 2>&1
	@${RM} ${LIBFT}/libft.a > /dev/null 2>&1 && echo "\r$(CHECK) Nettoyage complet réussi !" || { echo "\r$(CROSS) Échec du nettoyage complet !"; exit 1; }

re: fclean all
	@echo "$(BOLD)$(BLUE)Reconstruction terminée !$(RESET)"

.PHONY: all clean fclean re init_progress