# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdara <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 08:56:06 by gdara             #+#    #+#              #
#    Updated: 2021/12/11 08:56:11 by gdara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

HEADER	= ft_printf.h

SRC		= ft_printf.c\
			ft_printf_utils.c


OBJ		= ${patsubst %.c,%.o,${SRC}}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
			ar rcs ${NAME} $?

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
