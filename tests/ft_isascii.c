/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:51:02 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 14:53:20 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	int	c;

	// test 1
	set_description("Test 'null byte' is ascii");
	c = 0;
	check_is_equal(INT, ft_isascii(c), 1);
	
	// test 2
	set_description("Test '<DEL>' is ascii");
	c = 127;
	check_is_equal(INT, ft_isascii(c), 1);

	// test 3
	set_description("Test 'space' is ascii");
	c = 32;
	check_is_equal(INT, ft_isascii(c), 1);

	// test 4
	set_description("Test '<€>' from extended ascii is ascii");
	c = 128;
	check_is_equal(INT, ft_isascii(c), 1);

	// test 5
	set_description("Test '<ÿ>' from extended ascii is ascii");
	c = 255;
	check_is_equal(INT, ft_isascii(c), 1);


	return (0);
}
