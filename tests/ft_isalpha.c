/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:02:25 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 11:16:16 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	signal(SIGSEGV, &segfault_handler);
	
	char	c;

	// Test 1
	set_description("Test 'h' is alpha");
	c = 'h';
	check_is_equal(INT, ft_isalpha(c), 1);

	// Test 2
	set_description("Test 'a' is alpha");
	c = 'a';
	check_is_equal(INT, ft_isalpha(c), 1);
	
	// Test 3
	set_description("Test 'z' is alpha");
	c = 'z';
	check_is_equal(INT, ft_isalpha(c), 1);
	
	// Test 4
	set_description("Test 'A' is alpha");
	c = 'A';
	check_is_equal(INT, ft_isalpha(c), 1);

	// Test 5
	set_description("Test 'Z' is alpha");
	c = 'Z';
	check_is_equal(INT, ft_isalpha(c), 1);

	// Test 6
	set_description("Test null byte not is alpha");
	c = '\0';
	check_is_equal(INT, ft_isalpha(c), 0);

	// Test 7
	set_description("Test '0' is not alpha");
	c = '0';
	check_is_equal(INT, ft_isalpha(c), 0);
	
	// Test 8
	set_description("Test '9' is not alpha");
	c = '9';
	check_is_equal(INT, ft_isalpha(c), 0);
}
