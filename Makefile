# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:50:44 by kilchenk          #+#    #+#              #
#    Updated: 2023/11/08 19:53:04 by kilchenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRC = src
OBJ = $(SRCS:.c=.o)

INC = inc
CFLAGS = -Wextra -Werror -Wall -pthread -fsanitize=address -g -I $(INC)
#DEBUG_SEG_FAULTS = -fsanitize=address #for segfault checking
SRCS = src/main.c
RM = rm -rf
CC = gcc
		

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;35m••••\033[0m\c"
	@echo "\033[0;35m••••\033[0m\c"
	@echo "\033[0;35m••••\033[0m\c"

$(NAME): $(OBJ) $(SRC)
		@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
		
clean:
	@$(RM) $(OBJ)
	@echo "\033[0;34m✨Philosophers successfully cleaned!✨\033[0m"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean art re