/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:41:44 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 14:53:10 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	char	c;

	// test 1
	set_description("Test 'h' is printable");
	c = 104;
	check_is_equal(INT, ft_isprint(c), 1);

	// test 2
	set_description("Test space is printable");
	c = 32;
	check_is_equal(INT, ft_isprint(c), 1);

	// test 3
	set_description("Test <~> is printable");
	c = 126;
	check_is_equal(INT, ft_isprint(c), 1);
	
	// test 4
	set_description("Test <US (unit separator)> is not printable");
	c = 31;
	check_is_equal(INT, ft_isprint(c), 0);
	
	// test 5
	set_description("Test <DEL> is not printable");
	c = 127;
	check_is_equal(INT, ft_isprint(c), 0);
	
	// test 6
	set_description("Test <null byte> is not printable");
	c = 0;
	check_is_equal(INT, ft_isprint(c), 0);
	
	return (0);
}
