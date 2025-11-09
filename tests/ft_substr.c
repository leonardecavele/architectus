/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:11:09 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 23:11:31 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>

void	test1(void)
{
	char	*s;

	set_description("Extract a normal substring from the middle.");
	s = ft_substr("libft_tester", 6, 6);
	check_is_equal(STR, s, "tester");
	free(s);
}

void	test2(void)
{
	char	*s;

	set_description("Extract substring starting at index 0.");
	s = ft_substr("hello", 0, 2);
	check_is_equal(STR, s, "he");
	free(s);
}

void	test3(void)
{
	char	*s;

	set_description("Extract substring longer than the string.");
	s = ft_substr("abc", 0, 10);
	check_is_equal(STR, s, "abc");
	free(s);
}

void	test4(void)
{
	char	*s;

	set_description("Start index beyond string length should return empty string.");
	s = ft_substr("hello", 10, 3);
	check_is_equal(STR, s, "");
	free(s);
}

void	test5(void)
{
	char	*s;

	set_description("Zero length should return empty string.");
	s = ft_substr("hello", 1, 0);
	check_is_equal(STR, s, "");
	free(s);
}

void	test6(void)
{
	ft_substr(NULL, 0, 3);
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	handle(&test4);
	handle(&test5);
	handle_sigsegv("NULL string should segfault", &test6, NO_SEGFAULT);
}
