/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:11:35 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 14:53:25 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char	c;
	
	// Test 1
	set_description("Test '0' is alnum");
	c = '0';
	check_is_equal(INT, ft_isalnum(c), 1);
	
	// Test 2
	set_description("Test '9' is alnum");
	c = '9';
	check_is_equal(INT, ft_isalnum(c), 1);

	// Test 3
	set_description("Test 'h' is alnum");
	c = 'h';
	check_is_equal(INT, ft_isalnum(c), 1);

	// Test 4
	set_description("Test 'a' is alnum");
	c = 'a';
	check_is_equal(INT, ft_isalnum(c), 1);
	
	// Test 5
	set_description("Test 'z' is alnum");
	c = 'z';
	check_is_equal(INT, ft_isalnum(c), 1);
	
	// Test 6
	set_description("Test 'A' is alnum");
	c = 'A';
	check_is_equal(INT, ft_isalnum(c), 1);

	// Test 7
	set_description("Test 'Z' is alnum");
	c = 'Z';
	check_is_equal(INT, ft_isalnum(c), 1);

	// Test 8
	set_description("Test null byte is not alnum");
	c = '\0';
	check_is_equal(INT, ft_isalnum(c), 0);

		
	return (0);
}
