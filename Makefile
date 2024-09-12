# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimao <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 19:06:16 by asimao            #+#    #+#              #
#    Updated: 2024/08/02 11:11:01 by asimao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

SRC_CLIENT = client.c utils.c

SRC_SERVER = server.c utils.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

${NAME}: ${CLIENT} ${SERVER}

${CLIENT}: ${OBJ_CLIENT}
	${CC} ${CFLAGS} -o ${CLIENT} ${OBJ_CLIENT}

${SERVER}: ${OBJ_SERVER}
		${CC} ${CFLAGS} -o ${SERVER} ${OBJ_SERVER}

clean:
	${RM} ${OBJ_SERVER}
	${RM} ${OBJ_CLIENT}

fclean: clean
	${RM} ${CLIENT} ${SERVER}

re: fclean all

.PHONY: re all clean fclean
