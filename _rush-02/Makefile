# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 15:52:43 by hhonorio          #+#    #+#              #
#    Updated: 2026/02/01 16:14:35 by dieandra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Iincludes

SRC_FILES = $(wildcard src/*.c)
UTIL_FILES = $(wildcard utils/*.c)

OBJ = $(SRC_FILES:.c=.o) $(UTIL_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

utils/%.o: utils/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

