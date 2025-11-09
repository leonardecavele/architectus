/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:32:18 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 22:24:54 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


static char	*g_actual_name = "actual";
static char	*g_expected_name = "expected";
static char	*g_description = "";
static int	g_counter_main = 1;
static int	g_counter_inproc = 1;

static int	_run(void (*f)(void))
{
	pid_t	pid;
	int		status;

	pid = fork();
    if (pid == 0)
    {
		f();
        exit(0);
    }
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status))
        return (WTERMSIG(status));
    else
		return (0);
}

static void	_print_line(char *title, uint64_t res, t_type type, char *color)
{
	printf("%s∎%s %-10s|%s", color, RESET, title, color);
	switch (type)
	{
		case SIZE_T:
			printf("%ld", (size_t)res); break ;
		case INT:
			printf("%d", (int)res); break ;
		case CHAR:
			printf("%c", (int)res); break ;
		case STR:
			printf("%s", (char *)res); break ;
		case PTR:
			printf("%p", (void *)res); break ;
		default:
			printf("unknown type '%d'\n", type);
	}
	printf("%s|\n", RESET);
}

static void	_log_result(t_type type, _Bool ok, ...)
{
	uint64_t	a, b;

	char	*color = (ok) ? GREEN : RED;

	va_list	args;
	va_start(args, ok);
	a = (uint64_t)va_arg(args, uint64_t);
	b = (uint64_t)va_arg(args, uint64_t);
	va_end(args);
	display_description();
	_print_line(g_actual_name, a, type, color);
	_print_line(g_expected_name, b, type, color);
	g_counter_inproc++;
}

void	display_description()
{
	printf("\n─ %d.%d ─ %s ⸺\n", g_counter_main, g_counter_inproc, g_description);
}

void	set_description(const char *description)
{
	g_description = (char *)description;
}

void	set_display(const char *actual_name, const char *expected_name)
{
	g_actual_name = (char *)actual_name;
	g_expected_name = (char *)expected_name;
}

void	handle(void (*f)(void))
{
	int	status;

	g_counter_inproc = 1;
	status = _run(f);
	if (status == SIGSEGV)
		printf("%s∎%s |%sSegfault%s|\n", RED, RESET, RED, RESET);
	g_counter_main++;
}

void	handle_sigsegv(const char *description, void (*f)(void), bool must_segfault)
{
	int		status;
	char	*actual;
	char	*expected;

	g_counter_inproc = 1;
	status = _run(f);
	set_description(description);
	actual = (status == SIGSEGV) ? "Segfault" : "No Segfault";
	expected = (must_segfault) ? "Segfault" : "No Segfault";
	check_is_equal(STR, actual, expected);
	g_counter_main++;
}

void check_is_equal(t_type type, ...)
{
	uint64_t	a, b;
	int			ok;
	
	va_list	args;
	va_start(args, type);
	va_end(args);

	ok = 0;
	switch (type)
	{
		case SIZE_T:
		case PTR:
		case INT:
		case CHAR:
			a = va_arg(args, uint64_t);
			b = va_arg(args, uint64_t);
			ok = (a == b);
			_log_result(type, ok, a, b);
			break ;
		case STR:
			a = va_arg(args, uint64_t);
			b = va_arg(args, uint64_t);
			if (!a && !b)
				ok = 1;
			else
				ok = (!strcmp((char *)a, (char *)b));
			_log_result(type, ok, a, b);
			break ;
	}
}
