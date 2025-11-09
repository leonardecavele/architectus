/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:18:53 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 11:15:54 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	signal(SIGSEGV, &segfault_handler);

	char	*test;

	// test 1
	set_description("Test regular number");
	test = "9000";
	check_is_equal(INT, ft_atoi(test), atoi(test));
	
	// test 2
	set_description("Test regular number with one '+' sign");
	test = "+5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
	
	// test 3
	set_description("Test regular number with one '-' sign");
	test = "-5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
	
	// test 4
	set_description("Test regular number with multiple '+' sign");
	test = "++++5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
	
	// test 5
	set_description("Test regular number with multiple '-' sign");
	test = "-----5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 6
	set_description("Test regular number with multiple '+-' sign");
	test = "+--+---+5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 7
	set_description("Test regular number with one ' '");
	test = " 5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 8
	set_description("Test regular number with multiple ' '");
	test = "     5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 9
	set_description("Test regular number with one ' +' sign");
	test = " +5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 10
	set_description("Test regular number with multiple ' ' and one '+' sign");
	test = "      +5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 11
	set_description("Test regular number with multiple ' ' and multiple '-' sign");
	test = "      -----5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 12
	set_description("Test regular number followed by non digit chars");
	test = "42hello";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 13
	set_description("Test regular number preceded by multiple ' ', one '+' sign and one non digit");
	test = "     +a42";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 14
	set_description("Test number 0");
	test = "0";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 15
	set_description("Test INT_MAX");
	test = "2147483647";
	check_is_equal(INT, ft_atoi(test), atoi(test));	

	// test 16
	set_description("Test INT_MIN");
	test = "-2147483648";
	check_is_equal(INT, ft_atoi(test), atoi(test));

	// test 17
	set_description("Test INT underflow");
	test = "-2147483660";
	check_is_equal(INT, ft_atoi(test), atoi(test));

	// test 18
	set_description("Test INT overflow");
	test = "2147483660";
	check_is_equal(INT, ft_atoi(test), atoi(test));

	return (0);
}
