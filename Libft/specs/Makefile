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
	@FAILED=0; \
	for bin in $(BINS); do \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(YELLOW)  $$bin$(RESET)"; \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		./$$bin > /tmp/$$bin.out 2>&1; STATUS=$$?; \
		cat /tmp/$$bin.out | \
			sed 's/.*PASS.*/$(GREEN)&$(RESET)/' | \
			sed 's/.*FAIL.*/$(RED)&$(RESET)/'; \
		if [ $$STATUS -ne 0 ]; then FAILED=1; fi; \
	done; \
	echo ""; \
	if [ $$FAILED -eq 0 ]; then \
		echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(GREEN)  All tests passed!$(RESET)"; \
		echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		open -a "Google Chrome" "img/leonardo dicaprio bravo GIF.gif"; \
	else \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(RED)  Some tests failed!$(RESET)"; \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		open -a "Google Chrome" "img/Fabio Porchat GIF by Porta Dos Fundos.gif"; \
	fi

clean:
	rm -f $(BINS)

.PHONY: all run clean
