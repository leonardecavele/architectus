/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:41:03 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/08 16:35:52 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char	*test;

	// test 1
	set_description("Test regular string");
	test = "Hello world";
	check_is_equal(T_INT, ft_strlen(test), strlen(test));
	
	// test 2
	set_description("Test empty string");
	test = "";
	check_is_equal(T_INT, ft_strlen(test), strlen(test));
	
	// test 3
	set_description("Test string with null terminated only");
	test = "\0";
	check_is_equal(T_INT, ft_strlen(test), strlen(test));
	
	return (0);
}
