# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdara <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 17:47:11 by gdara             #+#    #+#              #
#    Updated: 2022/03/13 17:47:11 by gdara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
PHILO_NAME		= philo
CFLAGS 			= -g -Wall -Wextra -Werror -MMD

SRC 	= actions.c error.c philosophers.c time.c tools.c
INC =  philosophers.h

SRC_DIR 		= srcs/

PHILO		= $(addprefix $(SRC_DIR), $(SRC))
OBJS =  $(PHILO:.c=.o)
DEP =  $(PHILO:.c=.d)

all:			$(PHILO_NAME)

$(PHILO_NAME):	$(OBJS)
	@gcc $(CFLAGS) $(OBJS) -lpthread -o $(PHILO_NAME) 

clean:
	@rm -f $(OBJS) $(DEP)

fclean:			clean
	@rm -rf $(PHILO_NAME)

re:				fclean all

.PHONY:			all clean fclean re

-include $(DEP)