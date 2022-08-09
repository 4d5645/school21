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

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

SRC = main.c mandelbrot.c julia.c events.c tools.c errors.c

OBJS = $(SRC:.c=.o)

MLX		= ./minilibx/
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

all : $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_LNK) -lm -o $(NAME)

clean :
	@rm -rf $(OBJS)
	make -C $(MLX) clean

fclean : clean
	@rm -rf $(NAME)

re : fclean all
