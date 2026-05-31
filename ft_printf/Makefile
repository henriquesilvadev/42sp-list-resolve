# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 16:02:56 by hhonorio          #+#    #+#              #
#    Updated: 2026/05/31 12:14:21 by hhonorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

LIBFT_DIR = ./libft
LIBFT	=	$(LIBFT_DIR)/libft.a

SRCS    = ft_printf.c \
          handle_conversion.c \
		  ft_putnbr_base_fd.c \
		  ft_putnbr.c 

OBJS    = $(SRCS:%.c=objs/%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	ar rcs $@ $^

objs/%.o: %.c | objs
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

objs:
	mkdir -p objs

clean:
	$(RM) objs
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re objs test
