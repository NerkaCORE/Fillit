# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 10:18:53 by unli-yaw          #+#    #+#              #
#    Updated: 2016/12/14 17:50:31 by unli-yaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.sh

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB   = ./Libft/libft.a

SRC =	ft_parse.c			\
			main.c					\
			crea_te_tris.c	\
			algo.c					\
			algo_tools.c		\
			Check_tris.c		\
			map_op.c				\
			init_cfg.c			\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
	@make -C ./Libft
	@$(CC) $(CFLAGS) -I./Libft -o $(NAME) $(SRC) $(LIB)

clean :
	@make -C ./Libft clean
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME) $(LIB)

re : fclean all

.PHONY: all clean fclean re
