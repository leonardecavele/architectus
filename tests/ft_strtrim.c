/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:58:32 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 22:59:25 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>

void	test1(void)
{
	char	*s;

	set_description("Trim spaces from both ends of the string.");
	s = ft_strtrim("   hello world   ", " ");
	check_is_equal(STR, s, "hello world");
	free(s);
}

void	test2(void)
{
	char	*s;

	set_description("Trim multiple different characters.");
	s = ft_strtrim("--__42school__--", "-_");
	check_is_equal(STR, s, "42school");
	free(s);
}

void	test3(void)
{
	char	*s;

	set_description("Trim set that doesn't exist in the string.");
	s = ft_strtrim("hello", "xyz");
	check_is_equal(STR, s, "hello");
	free(s);
}

void	test4(void)
{
	char	*s;

	set_description("Trim everything from string containing only characters from set.");
	s = ft_strtrim("xxxx", "x");
	check_is_equal(STR, s, "");
	free(s);
}

void	test5(void)
{
	ft_strtrim(NULL, "x");
}

void	test6(void)
{
	ft_strtrim("hello", NULL);
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	handle(&test4);
	handle_sigsegv("NULL string should segfault", &test5, NO_SEGFAULT);
	handle_sigsegv("NULL set should segfault", &test6, NO_SEGFAULT);
}
