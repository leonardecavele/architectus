/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:50:59 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 12:01:37 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	signal(SIGSEGV, &segfault_handler);

	char	*ft_dest;
	char	*dest;
	char	*src;
	int		size;

	// test 1
	set_description("Test regular string");
	ft_dest = malloc(10); dest = malloc(10);
	src = "Hello world";
	size = 5;
	check_is_equal(SIZE_T,
	ft_strlcpy(ft_dest, src, size),
	strlcpy(dest, src, size));

	set_description("Empty dest");
	ft_dest = ""; dest = "";
	src = "Hello";
	size = 5;
	check_is_equal(SIZE_T,
	ft_strlcpy(ft_dest, src, size),
	strlcpy(dest, src, size));
	
	return (0);
}
