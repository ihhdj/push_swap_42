# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 12:09:38 by ihhadjal          #+#    #+#              #
#    Updated: 2025/01/17 14:24:27 by iheb             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = code/main.c code/parsing.c code/utils.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./resources/libft

all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./resources/libft
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./resources/libft/libft.a

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	${MAKE} clean -C ./resources/libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./resources/libft/libft.a

re: fclean all
.PHONY: all clean fclean re