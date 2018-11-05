# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 13:39:20 by mmuamba           #+#    #+#              #
#    Updated: 2018/08/07 14:57:02 by mmuamba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moses.filler
CC = gcc -o
FLAGS = -Wall -Wextra -Werror
INC = -I ./includes/
LIB = ./libft/
SRC = ./srcs/*.c
RM = rm -rf
$(NAME):
	@make -C $(LIB)
	@$(CC) $(NAME) $(FLAGS) $(SRC) $(INC) -L libft/ -lft
	@echo "-- Player Compiled Successfully --"
all: $(NAME)
clean:
	@make clean -C $(LIB)
fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME)
	@echo "-- Player Cleaned --"
re: fclean all
