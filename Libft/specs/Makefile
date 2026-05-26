# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 08:30:38 by hhonorio          #+#    #+#              #
#    Updated: 2026/05/26 15:48:22 by hhonorio         ###   ########.fr        #
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
		sed 's/.*error.*/$(RED)&$(RESET)/'; true

run: all
	@FAILED=0; \
	for bin in $(BINS); do \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(YELLOW)  $$bin$(RESET)"; \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		if [ ! -f ./$$bin ]; then \
			echo "$(RED)  $$bin: falhou ao compilar$(RESET)"; \
			FAILED=1; \
			continue; \
		fi; \
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
			if [ ! -f ./$$bin ]; then \
				printf "  \033[0;31m%-20s | %-24s | %s\033[0m\n" "$$bin" "-" "falhou ao compilar"; \
				continue; \
			fi; \
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

norminette:
	@NORM_FAILED=0; \
	echo ""; \
	echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
	echo "$(YELLOW)  Norminette Report$(RESET)"; \
	echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
	echo ""; \
	printf "  %-20s | %s\n" "Arquivo" "Status"; \
	printf "  %-20s-+-%s\n" "--------------------" "-------------------------------------"; \
	for file in $(LIBFT_SRCS) ../libft.h; do \
		fname=$$(basename $$file); \
		norminette $$file > /tmp/norm_$$fname.out 2>&1; \
		if grep -q "Error" /tmp/norm_$$fname.out; then \
			printf "  $(RED)%-20s | ✗ norminette error$(RESET)\n" "$$fname"; \
			NORM_FAILED=1; \
		else \
			printf "  $(GREEN)%-20s | ✓ ok$(RESET)\n" "$$fname"; \
		fi; \
	done; \
	echo ""; \
	if [ $$NORM_FAILED -eq 0 ]; then \
		echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(GREEN)  Norminette passed!$(RESET)"; \
		echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		open "img/No Problem Yes GIF by Vevo.gif"; \
	else \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(RED)  Norminette errors found!$(RESET)"; \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo ""; \
		echo "  Run $(YELLOW)make norminette_verbose$(RESET) for full details."; \
		open "img/Cry Baby Crying GIF by Luis Ricardo.gif"; \
	fi

norminette_verbose:
	@for file in $(LIBFT_SRCS) ../libft.h; do \
		fname=$$(basename $$file); \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(YELLOW)  $$fname$(RESET)"; \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		norminette $$file 2>&1; \
		echo ""; \
	done

valgrind: clean all
	@LEAKS=0; \
	echo ""; \
	echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
	echo "$(YELLOW)  Memory Leak Report$(RESET)"; \
	echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
	echo ""; \
	printf "  %-20s | %s\n" "Função" "Status"; \
	printf "  %-20s-+-%s\n" "--------------------" "-------------------------------------"; \
	for bin in $(BINS); do \
		if [ ! -f ./$$bin ]; then \
			printf "  %-20s | %s\n" "$$bin" "falhou ao compilar"; \
			continue; \
		fi; \
		valgrind --leak-check=full --error-exitcode=1 ./$$bin > /tmp/$$bin.valgrind 2>&1; VSTATUS=$$?; \
		LEAKED=$$(grep "definitely lost:" /tmp/$$bin.valgrind | awk '{print $$4}' | tr -d ','); \
		INDIRECT=$$(grep "indirectly lost:" /tmp/$$bin.valgrind | awk '{print $$4}' | tr -d ','); \
		ERRORS=$$(grep "ERROR SUMMARY:" /tmp/$$bin.valgrind | awk '{print $$4}'); \
		if [ "$$VSTATUS" -eq 0 ] && [ "$$ERRORS" = "0" ]; then \
			printf "  $(GREEN)%-20s | ✓ no leaks$(RESET)\n" "$$bin"; \
		else \
			printf "  $(RED)%-20s | ✗ leaked: %s bytes directly, %s indirectly$(RESET)\n" "$$bin" "$${LEAKED:-0}" "$${INDIRECT:-0}"; \
			LEAKS=1; \
		fi; \
	done; \
	echo ""; \
	if [ $$LEAKS -eq 0 ]; then \
		echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(GREEN)  No memory leaks found!$(RESET)"; \
		echo "$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		open "img/Images Repair GIF by getflexseal.gif"; \
	else \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(RED)  Memory leaks detected!$(RESET)"; \
		echo "$(RED)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo ""; \
		echo "  Run $(YELLOW)make valgrind_verbose$(RESET) for full details."; \
		open "img/Water Fail GIF.gif"; \
	fi

valgrind_verbose: all
	@for bin in $(BINS); do \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		echo "$(YELLOW)  $$bin$(RESET)"; \
		echo "$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$$bin 2>&1; \
		echo ""; \
	done

clean:
	rm -f $(BINS)

.PHONY: all run norminette norminette_verbose valgrind valgrind_verbose clean