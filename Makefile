# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 12:09:38 by ihhadjal          #+#    #+#              #
#    Updated: 2025/01/16 16:01:31 by ihhadjal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = code/main.c code/parsing.c
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