TESTS = $(wildcard $(TESTS_DIR)*.c)
BINARIES = $(TESTS:$(TESTS_DIR)%.c=%.ev)

.PHONY: .FORCE all clean r rb
SHELL := /bin/bash

CC = cc
CFLAGS = -Wall -Wextra -Werror -L ../ -lft
MAKE_FLAGS = -j $$(nproc)
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
	$(MAKE) $(MAKE_FLAGS) -C ../
	$(MAKE) bonus $(MAKE_FLAGS) -C ../

clean:
	rm -f *.ev

# relink
r:
	@read -n 1 -s -p "Appuyez sur une touche pour continuer..."
	@echo
	@make $(MAKE_FLAGS) fclean -C ../ --no-print-directory
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@touch ../ft_strlen.c 
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@touch ../libft.h
	@make $(MAKE_FLAGS) -C ../ --no-print-directory
	@make $(MAKE_FLAGS) fclean -C ../ --no-print-directory
