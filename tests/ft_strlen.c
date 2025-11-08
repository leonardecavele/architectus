/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:41:03 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/08 13:55:46 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	set_display("ft_strlen", "strlen");
	
	char *test = "Hello World";
	size_t actual = ft_strlen(test);
	size_t expected = strlen(test);
	check_is_equal(&actual, &expected, T_INT);
	return (0);
}
