# variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
SHELL := /bin/bash
TESTS_DIR = tests/
OUT_DIR = bin/
LIB = ../libft.a
BINARIES = $(patsubst %.c,$(OUT_DIR)%.test,$(TESTS))
BBINARIES = $(patsubst %.c,$(OUT_DIR)%.test,$(BTESTS)) 
ERR_TRAP = trap 'stty echo; echo -e "\033[0;31m[Error]\033[0m"; exit 1' ERR
# colors
RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
ERASE = \r\033[2K\r
YELLOW_B = \e[43m

.PHONY: .FORCE all clean r rb libft.a bonus
include list.mk

%.test: $(OUT_DIR)%.test
	@true

WAIT := 0
# 'make' to test all functions at once
all: $(BINARIES) $(BBINARIES)
# 'make m' to test only the mandatory part functions
m: $(BINARIES)
# 'make b' to test only the bonus part functions
b: $(BBINARIES)
# 'make {function.test}' to test a single function
.ONESHELL:
$(OUT_DIR)%.test: $(TESTS_DIR)%.c libft.a .FORCE
	@stty -echo
	@mkdir -p $(OUT_DIR)
	@$(ERR_TRAP); \
	WAIT=$(WAIT) ; if [ "$$WAIT" -eq 1 ]; then printf \
	"\npress any key" ; read -n 1 -s ; printf "$(ERASE)" ;\
	fi ; $(eval WAIT:=1)
	@$(CC) $(CFLAGS) $< -o $@ $(SRCS) -L ../ -lft -lbsd
	@printf "|$(YELLOW_B)%s$(RESET)|\n" $(subst bin/,,$(subst .test,,$@))
	@./$@
	@stty echo

# 'make clean' to delete .test files
clean:
	@rm -rf $(OUT_DIR)
# 'make fclean' to delete libft.a and .test files
fclean: clean
	@$(MAKE) fclean -C ../ --quiet

search:
	@$(ERR_TRAP); \
	SORTED=$$(printf "%s\n" $(MUSTFILES) | sort);\
	M=$$(comm -23 <(echo "$$SORTED") <(echo "$$LIST"));\
	E=$$(comm -13 <(echo "$$SORTED") <(echo "$$LIST"));\
	if [ -z "$$M" ] && [ -z "$$E" ]; then\
		printf "$(GREEN)NO MISSING NOR EXTRA FILE$(RESET)\n";\
	else\
		[ ! -z "$$M" ] && printf "$(RED)MISSING FILES:\n%s$(RESET)\n" "$$M";\
		[ ! -z "$$E" ] && printf "$(RED)EXTRA FILES:\n%s$(RESET)\n" "$$E";\
	fi;\
	true
# 'make check' to check files
check:
	@$(ERR_TRAP); \
	LIST=$$(find ../ -maxdepth 1 -type f ! -name "*.o" ! -name "*_bonus*" ! -name "*.d" -printf "%f\n" | sort);\
	$(MAKE) search LIST="$$LIST" --no-print-directory
# 'make checkb' to check bonus files
checkb:
	@$(ERR_TRAP); \
	LIST=$$(find ../ -maxdepth 1 -type f ! -name "*.o" ! -name "*.d" -printf "%f\n" | sort);\
	$(MAKE) search MUSTFILES="$(MUSTFILES) $(BTESTS)" LIST="$$LIST" --no-print-directory

# 'make n' to test the norm
n: fclean
	@$(ERR_TRAP); \
	printf "|$(YELLOW_B)NORM CHECK$(RESET)|\n"
	@find .. -maxdepth 1 -type f \( -name "*.c" -o -name "*.h" \) \
	| xargs norminette -R CheckForbiddenSourceHeader

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
	@$(MAKE) -C ../ > /dev/null 2>&1
	@$(MAKE) bonus -C ../ > /dev/null 2>&1 
# 'make libft.a' to rebuild the libft.a
libft.a:
	@$(ERR_TRAP); \
	stty -echo;\
	printf "[$(RED)BUILDING$(RESET)] 'libft.a'$(RESET)";\
	$(MAKE) fclean -C ../ --quiet ; make $(LIB) --no-print-directory ;\
	printf "$(ERASE)[$(GREEN)DONE$(RESET)] 'libft.a'$(RESET)\n";\
	if ! echo "$(MAKECMDGOALS)" | grep -qE "libft.a"; then echo; fi;\
	stty echo;\
