# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdara <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 18:47:11 by gdara             #+#    #+#              #
#    Updated: 2021/11/09 10:05:33 by gdara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
	  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c

LIBSRC = $(patsubst %.c, %.o, $(SRC))

BONUSFUNC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		   	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		   	ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUSLIB = $(patsubst %.c, %.o, $(BONUSFUNC))

HEADER = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		 ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
		 ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		 ft_split.c ft_itoa.c ft_strmapi.c

HEADERLIB = $(patsubst %.c, %.o, $(HEADER))

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(HEADERLIB): libft.h

%.o : %.c
	gcc $(FLAGS) -c $<

$(NAME): $(LIBSRC) $(HEADERLIB)
	ar rcs $(NAME) $?

clean:
	/bin/rm -f $(LIBSRC) $(BONUSLIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus:
	gcc $(FLAGS) -c $(BONUSFUNC)
	ar rcs $(NAME) $(BONUSLIB)

