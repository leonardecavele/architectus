/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:18:53 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 23:41:08 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int atoi(const char *nptr);

static char *test;

void test1(void)
{
	set_description("Test regular number");
	test = "9000";
	check_is_equal(INT, ft_atoi(test), atoi(test));
}

void test2(void)
{
	set_description("Test regular number with one '+' sign");
	test = "+5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test3(void)
{
	set_description("Test regular number with one '-' sign");
	test = "-5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test4(void)
{
	set_description("Test regular number with multiple '+' sign");
	test = "++++5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test5(void)
{
	set_description("Test regular number with multiple '-' sign");
	test = "-----5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test6(void)
{
	set_description("Test regular number with multiple '+-' sign");
	test = "+--+---+5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test7(void)
{
	set_description("Test regular number with one ' '");
	test = " 5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test8(void)
{
	set_description("Test regular number with multiple ' '");
	test = "     5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test9(void)
{
	set_description("Test regular number with one ' +' sign");
	test = " +5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test10(void)
{
	set_description("Test regular number with multiple ' ' and one '+' sign");
	test = "      +5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test11(void)
{
	set_description("Test regular number with multiple ' ' and multiple '-' sign");
	test = "      -----5000";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test12(void)
{
	set_description("Test regular number followed by non digit chars");
	test = "42hello";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test13(void)
{
	set_description("Test regular number preceded by multiple ' ', one '+' sign and one non digit");
	test = "     +a42";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test14(void)
{
	set_description("Test number 0");
	test = "0";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test15(void)
{
	set_description("Test INT_MAX");
	test = "2147483647";
	check_is_equal(INT, ft_atoi(test), atoi(test));	
}

void test16(void)
{
	set_description("Test INT_MIN");
	test = "-2147483648";
	check_is_equal(INT, ft_atoi(test), atoi(test));
}

void test17(void)
{
	set_description("Test INT underflow");
	test = "-2147483660";
	check_is_equal(INT, ft_atoi(test), atoi(test));
}

void test18(void)
{
	set_description("Test INT overflow");
	test = "2147483660";
	check_is_equal(INT, ft_atoi(test), atoi(test));
}

int	main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	handle(&test4);
	handle(&test5);
	handle(&test6);
	handle(&test7);
	handle(&test8);
	handle(&test9);
	handle(&test10);
	handle(&test11);
	handle(&test12);
	handle(&test13);
	handle(&test14);
	handle(&test15);
	handle(&test16);
	handle(&test17);
	handle(&test18);

	return (0);
}
