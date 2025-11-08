# HOW TO USE :
# 'make' to test all functions at once
# 'make {function.test}' to test a single function
# 'make libft.a' to rebuild the libft.a
# 'make clean' to delete .test files
# 'make fclean' to delete libft.a and .test files
# 'make m' to test only the mandatory part functions
# 'make b' to test only the bonus part functions
# 'make re' does 'make fclean' and 'make all'
# 'make rb' to test bonus relink
# 'make n' to test the norm
# 'make r' to test mandatory relink

.PHONY: .FORCE all clean r rb libft.a bonus
include list.mk

BINARIES = $(patsubst %.c,$(OUT_DIR)%.test,$(TESTS))
BBINARIES = $(patsubst %.c,$(OUT_DIR)%.test,$(BTESTS)) 

SHELL := /bin/bash
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
TESTS_DIR = tests/
OUT_DIR = bin/
LIB = ../libft.a
wait := 0
SRCS = tester.c

# 'make' to test all functions at once
all: $(BINARIES) $(BBINARIES)

# 'make m' to test only the mandatory part functions
m: $(BINARIES)

# 'make b' to test only the bonus part functions
b: $(BBINARIES)

# 'make {function.test}' to test a single function
$(OUT_DIR)%.test: $(TESTS_DIR)%.c libft.a .FORCE
	@stty -echo
	@mkdir -p $(OUT_DIR)
	@wait=$(wait) ; if [ "$$wait" -eq 1 ]; then printf \
	"\npress any key" ; read -n 1 -s ; printf "$(ERASE)" ;\
	fi ; $(eval wait:=1)
	@$(CC) $(CFLAGS) $< -o $@ $(SRCS) -L ../ -lft
	@printf "|$(YELLOW_B)%s$(RESET)|\n" $(subst .test,.c,$@)
	@./$@
	@stty echo

# 'make n' to test the norm
n: fclean
	@printf "|$(YELLOW_B)NORM CHECK$(RESET)|\n"
	@find .. -maxdepth 1 -type f \( -name "*.c" -o -name "*.h" \) \
	| xargs norminette -R CheckForbiddenSourceHeader

# 'make libft.a' to rebuild the libft.a
libft.a:
	@if [ ! -f $(LIB) ]; then\
		stty -echo;\
		printf "[$(RED)BUILDING$(RESET)] 'libft.a'$(RESET)";\
		$(MAKE) fclean -C ../ --quiet ; make $(LIB) --no-print-directory ;\
		printf "$(ERASE)[$(GREEN)DONE$(RESET)] 'libft.a'$(RESET)\n";\
		if ! echo "$(MAKECMDGOALS)" | grep -qE "libft.a"; then echo; fi;\
		stty echo;\
	fi

# 'make clean' to delete .test files
clean:
	@rm -rf $(OUT_DIR)

# 'make fclean' to delete libft.a and .test files
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
	@if [ "$$BONUS" = "1" ]; then touch ../ft_lstadd_back_bonus.c;\
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
