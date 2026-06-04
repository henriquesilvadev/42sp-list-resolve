# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 16:02:56 by hhonorio          #+#    #+#              #
#    Updated: 2026/06/04 12:48:40 by hhonorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

LIBFT_DIR = ./include/libft
LIBFT	=	$(LIBFT_DIR)/libft.a

SRCS    = src/ft_printf.c \
          src/handle_conversion.c \
		  src/ft_putnbr_base_fd.c \
		  src/ft_putnbr.c \
		  src/parser_conversion.c \
		  src/print_nbr_base.c

OBJS = $(SRCS:src/%.c=objs/%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $@
	ar rcs $@ $^

objs/%.o: src/%.c | objs
	$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -c $< -o $@

objs:
	mkdir -p objs

clean:
	$(RM) objs
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re objs
