# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdara <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:52:33 by gdara             #+#    #+#              #
#    Updated: 2022/02/14 10:52:33 by gdara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HDR_DIR = inc/

SRC_DIR = src/

LIBFTDIR = ./libft/

RM = rm -f

HDR = pipex.h

SRC = pipex.c path_functions.c error.c

LIBFT_NAME = libft.a

HEADERS = $(addprefix ${HDRS_DIR}, ${HDRS})

SOURCES = $(addprefix ${SRC_DIR}, ${SRC})

LIBFT = $(addprefix ${LIBFTDIR}, ${LIBFT_NAME})

all:	${LIBFT} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}:	${SOURCES} ${HEADERS} ${LIBFT}
	${CC} ${CFLAGS} ${SOURCES} -L ${LIBFTDIR} -lft -o $@

clean:
	${MAKE} clean -C ${LIBFTDIR}

fclean:		clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re:	fclean all

.PHONY:	clean all fclean re