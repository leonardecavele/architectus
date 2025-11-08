/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:32:18 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/08 16:35:07 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static char	*s_actual_name = "actual";
static char	*s_expected_name = "expected";
static char	*s_description = "";
static int	s_counter = 1;

static void	_log_result(t_vtype type, _Bool ok, ...)
{
	uint64_t	a, b;

	char	*color = (ok) ? GREEN : RED;

	va_list	args;
	va_start(args, ok);

	printf("\n─ %d ─ %s ⸺\n", s_counter, s_description);

	switch (type)
	{
		case T_INT:
			a = (uint64_t)va_arg(args, int);
			b = (uint64_t)va_arg(args, int);
			printf("%s∎%s %-10s|%s%d%s|\n", color, RESET, s_actual_name, color, (int)a, RESET);
			printf("%s∎%s %-10s|%s%d%s|\n", color, RESET, s_expected_name, color, (int)b, RESET);
			break ;
		case T_CHAR:
			a = (uint64_t)va_arg(args, int);
			b = (uint64_t)va_arg(args, int);
			printf("%-10s |%s%c%s|\n", s_actual_name, color, (char)a, RESET);
			printf("%-10s |%s%c%s|\n", s_expected_name, color, (char)b, RESET);
			break ;
		default:
			printf("Type unknown: %d\n", type);
	}
	s_counter++;
}

void	set_description(const char *description)
{
	s_description = (char *)description;
}

void	set_display(const char *actual_name, const char *expected_name)
{
	s_actual_name = (char *)actual_name;
	s_expected_name = (char *)expected_name;
}

void check_is_equal(t_vtype type, ...)
{
	uint64_t	a, b;
	int			ok;
	
	va_list	args;
	va_start(args, type);

	ok = 0;
	switch (type)
	{
		case T_INT:
		case T_CHAR:
			a = (uint64_t)va_arg(args, int);
			b = (uint64_t)va_arg(args, int);
			ok = (a == b);
			_log_result(type, ok, a, b);
			break ;
		case T_STR:
			a = (uint64_t)va_arg(args, char *);
			b = (uint64_t)va_arg(args, char *);	
			ok = (strcmp((char *)a, (char *)b) == 0);
			_log_result(type, ok, a, b);
			break ;
	}
	
}
