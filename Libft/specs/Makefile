# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 08:30:38 by hhonorio          #+#    #+#              #
#    Updated: 2026/05/24 13:54:46 by hhonorio         ###   ########.fr        #
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
		open "img/leonardo dicaprio bravo GIF.gif"; \
	else \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(RED)  Some tests failed!$(RESET)"; \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo ""; \
		printf "  \033[0;31m%-20s | %-24s | %s\033[0m\n" "Função" "Teste" "Descrição do erro"; \
		printf "  \033[0;31m%-20s-+-%-24s-+-%s\033[0m\n" "--------------------" "------------------------" "-------------------------------------"; \
		for bin in $(BINS); do \
			if [ -f /tmp/$$bin.out ] && grep -q "^FAIL" /tmp/$$bin.out 2>/dev/null; then \
				fname="$$bin"; exp=""; got=""; \
				while IFS= read -r ln; do \
					case "$$ln" in \
						"Expected: "*) exp="$${ln#Expected: }" ;; \
						*"Got: "*) got="$${ln##*Got: }" ;; \
						FAIL*) \
							tn=$$(echo "$$ln" | sed 's/^FAIL \([^:]*\):.*/\1/'); \
							if [ -n "$$exp" ]; then \
								desc="esperado '$$exp'  obtido '$$got'"; exp=""; got=""; \
							else \
								desc=$$(echo "$$ln" | sed 's/^FAIL [^:]*: //' | sed 's/ ([^)]*)$$//'); \
							fi; \
							printf "  \033[0;31m%-20s | %-24s | %s\033[0m\n" "$$fname" "$$tn" "$$desc"; \
							fname="" ;; \
					esac; \
				done < /tmp/$$bin.out; \
			fi; \
		done; \
		printf "  \033[0;31m%-20s-+-%-24s-+-%s\033[0m\n" "--------------------" "------------------------" "-------------------------------------"; \
		echo ""; \
		open "img/Fabio Porchat GIF by Porta Dos Fundos.gif"; \
	fi

clean:
	rm -f $(BINS)

.PHONY: all run clean
