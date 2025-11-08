TESTS = $(wildcard $(TESTS_DIR)*.c)
BINARIES = $(TESTS:$(TESTS_DIR)%.c=%.ev)

.PHONY: .FORCE all clean r rb

BONUS_FLAG =
SHELL := /bin/bash
CC = cc
CFLAGS = -Wall -Wextra -Werror -L ../ -lft
TESTS_DIR = tests/
LIB = ../libft.a

all: $(BINARIES)

# run make {name of function with '.ev' to test}
%.ev: $(TESTS_DIR)%.c $(LIB) .FORCE
	$(CC) $(CFLAGS) $< $(LIB) -o $@
	./$@

# rebuild lib
$(LIB):
	$(MAKE) fclean -C ../
	$(MAKE) $(BONUS_FLAG) -C ../
	$(MAKE) bonus $(BONUS_FLAG) -C ../

clean:
	rm -f *.ev

rb:
	@$(MAKE) BONUS_FLAG="bonus $(BONUS_FLAG)" r BONUS=1 --no-print-directory

# relink
r:
	@printf "\033[1;31mDouble make:\033[1;30m\n"
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory 
	@printf "\033[1;31mC files relink:\033[0;30m\n"
	@if [ "$$BONUS" = "1" ]; then touch ../ft_lstadd_back_bonus.c; \
	else touch ../ft_strlen.c; fi
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@printf "\033[1;31mHeaders relink:\033[0;30m\n"
	@touch ../libft.h
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 
