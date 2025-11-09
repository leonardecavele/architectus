/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:10:44 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 11:16:11 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	signal(SIGSEGV, &segfault_handler);
	
	char	c;
	
	// Test 1
	set_description("Test '0' is digit");
	c = '0';
	check_is_equal(INT, ft_isdigit(c), 1);
	
	// Test 2
	set_description("Test '9' is digit");
	c = '9';
	check_is_equal(INT, ft_isdigit(c), 1);

	// Test 3
	set_description("Test 'h' is not digit");
	c = 'h';
	check_is_equal(INT, ft_isdigit(c), 0);

	// Test 4
	set_description("Test 'a' is not digit");
	c = 'a';
	check_is_equal(INT, ft_isdigit(c), 0);
	
	// Test 5
	set_description("Test 'z' is not digit");
	c = 'z';
	check_is_equal(INT, ft_isdigit(c), 0);
	
	// Test 6
	set_description("Test 'A' is not digit");
	c = 'A';
	check_is_equal(INT, ft_isdigit(c), 0);

	// Test 7
	set_description("Test 'Z' is not digit");
	c = 'Z';
	check_is_equal(INT, ft_isdigit(c), 0);

	// Test 8
	set_description("Test null byte not is not digit");
	c = '\0';
	check_is_equal(INT, ft_isdigit(c), 0);

		
	return (0);
}
