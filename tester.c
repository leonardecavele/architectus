/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:32:18 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/08 13:50:28 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static char	*s_actual_name = "actual";
static char	*s_expected_name = "expected";

static void	_log_result(void *actual, void *expected, t_vtype vtype, _Bool ok)
{
	char	*color = (ok) ? GREEN : RED;
	char	* result = (ok) ? "ok" : "failed";

	switch (vtype)
	{
		case T_INT:
			int *a = (int *)actual;
			int *b = (int *)expected;
			printf("%s", color);
			fflush(stdout);
			printf("%-10s |%d|\n", s_actual_name, *a);
			printf("%-10s |%d|\n", s_expected_name, *b);
			break ;
		default:
			printf("Type unknown: %d\n", vtype);
	}

	printf("%s%s\n", result, RESET);
}

void	set_display(const char *actual_name, const char *expected_name)
{
	s_actual_name = (char *)actual_name;
	s_expected_name = (char *)expected_name;
}

void check_is_equal(const void *actual, const void *expected, t_vtype vtype)
{
	uint64_t	*a, *b;
	int			ok;

	a = (uint64_t *)actual;
	b = (uint64_t *)expected;

	ok = 0;
	switch (vtype)
	{
		case T_INT:
		case T_CHAR:
			ok = (*a == *b);
			break ;
		case T_STR:
			ok = (strcmp((char *)a, (char *)b) == 0);
			break ;
	}
	
	_log_result((void *)actual, (void *)expected, vtype, ok);
}
