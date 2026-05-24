# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 08:30:38 by hhonorio          #+#    #+#              #
#    Updated: 2026/05/24 09:21:41 by hhonorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -I. -I../
SRC_DIR = ../

TESTS   = $(wildcard *_test.c)
BINS    = $(patsubst %_test.c, %, $(TESTS))
LIBFT_SRCS = $(wildcard $(SRC_DIR)*.c)

# cores
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
RESET   = \033[0m

all: $(BINS)

%: %_test.c
	@$(CC) $(CFLAGS) $< $(LIBFT_SRCS) -o $@ 2>&1 | \
		sed 's/.*warning.*/$(YELLOW)&$(RESET)/' | \
		sed 's/.*error.*/$(RED)&$(RESET)/'

run: all
	@for bin in $(BINS); do \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(YELLOW)  ☕ $$bin$(RESET)"; \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		./$$bin 2>&1 | \
			sed 's/.*PASS.*/$(GREEN)&$(RESET)/' | \
			sed 's/.*FAIL.*/$(RED)&$(RESET)/'; \
	done; \
	echo ""; \
	echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
	echo "$(GREEN)  ☕ Brew complete — all tests done!$(RESET)"; \
	echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"

clean:
	rm -f $(BINS)

.PHONY: all run clean
