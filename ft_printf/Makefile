# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 16:02:56 by hhonorio          #+#    #+#              #
#    Updated: 2026/05/31 08:54:54 by hhonorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS    = ft_printf.c \
		  handle_conversion.c \
		  ft_putnbr_base_fd.c 

OBJS    = $(SRCS:src/%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

objs/%.o: src/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
