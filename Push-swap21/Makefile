# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdara <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 10:21:06 by gdara             #+#    #+#              #
#    Updated: 2022/02/03 10:21:11 by gdara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HDR_DIR = inc/

SRC_DIR = src/

LIBFTDIR = ./libft/

RM = rm -f

HDR = pushswap.h

SRC = lists.c pushswap_main.c initialization.c basic_comands.c write_and_close.c sort_three.c array_sort.c write_and_runcommand.c

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