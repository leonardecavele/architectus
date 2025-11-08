# HOW TO USE :
# 'make' to test all functions at once
# 'make {function.ev}' to test a single function
# 'make libft.a' to rebuild the libft.a
# 'make clean' to delete .ev files
# 'make fclean' to delete libft.a and .ev files
# 'make re' does 'make fclean' and 'make all'
# 'make rb' to test bonus relink
# 'make r' to test mandatory relink

.PHONY: .FORCE all clean r rb libft.a

TESTS = $(wildcard $(TESTS_DIR)*.c)
BINARIES = $(TESTS:$(TESTS_DIR)%.c=%.ev)

SHELL := /bin/bash
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
TESTS_DIR = tests/
LIB = ../libft.a
wait := 0
SRCS = tester.c

# 'make' to test all functions at once
all: $(BINARIES)

# 'make {function.ev}' to test a single function
%.ev: $(TESTS_DIR)%.c libft.a .FORCE
	@stty -echo
	@wait=$(wait) ; if [ "$$wait" -eq 1 ]; then printf \
	"\npress any key to continue.." ; read -n 1 -s ; printf "$(ERASE)" ; \
	fi ; $(eval wait:=1)
	@$(CC) $(CFLAGS) $< -o $@ $(SRCS) -L ../ -lft
	@printf "|$(YELLOW_B)%s$(RESET)|\n" $(subst .ev,.c,$@)
	@./$@
	@stty echo

# 'make libft.a' to rebuild the libft.a
libft.a:
	@if [ ! -f $(LIB) ]; then \
		stty -echo; \
		printf "[$(RED)BUILDING$(RESET)] 'libft.a'$(RESET)"; \
		$(MAKE) fclean -C ../ --quiet ; make $(LIB) --no-print-directory ;\
		printf "$(ERASE)[$(GREEN)DONE$(RESET)] 'libft.a'$(RESET)\n"; \
		if ! echo "$(MAKECMDGOALS)" | grep -qE "libft.a"; then echo; fi; \
		stty echo; \
	fi

# 'make clean' to delete .ev files
clean:
	@rm -f *.ev

# 'make fclean' to delete libft.a and .ev files
fclean: clean
	@$(MAKE) fclean -C ../ --quiet	

# 'make re' does 'make fclean' and 'make all'
re: fclean all

# 'make rb' to test bonus relink
rb:
	@$(MAKE) BONUS_FLAG="bonus $(BONUS_FLAG)" r BONUS=1 --no-print-directory

# 'make r' to test mandatory relink
r:
	@stty -echo
	@printf "|$(YELLOW_B)DOUBLE MAKE$(RESET)|\n"
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory > /dev/null 2>&1 
	@make $(BONUS_FLAG) -C ../ --no-print-directory 
	@printf "|$(YELLOW_B)TOUCH .C FILE AND RUN MAKE$(RESET)|\n"
	@if [ "$$BONUS" = "1" ]; then touch ../ft_lstadd_back_bonus.c; \
	else touch ../ft_strlen.c; fi
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@printf "|$(YELLOW_B)TOUCH HEADER AND RUN MAKE$(RESET)|\n"
	@touch ../libft.h
	@make $(BONUS_FLAG) -C ../ --no-print-directory
	@make $(BONUS_FLAG) fclean -C ../ --no-print-directory > /dev/null 2>&1 
	@stty echo

$(LIB):
	@$(MAKE)  -C ../ > /dev/null 2>&1
	@$(MAKE) bonus -C ../ > /dev/null 2>&1 

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
ERASE = \r\033[2K\r
YELLOW_B = \e[43m
