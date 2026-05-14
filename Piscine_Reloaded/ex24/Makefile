NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INC_DIR = includes

SRC =	$(SRC_DIR)/ft_putchar.c \
		$(SRC_DIR)/ft_putstr.c \
		$(SRC_DIR)/ft_strcmp.c \
		$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_swap.c

OBJ = $(SRC:.c=.o)

HEADER = $(INC_DIR)/ft.h

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re