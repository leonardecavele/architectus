/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:06:47 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 23:37:33 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int toupper(int c);

static int ft_res, res, c;

void	test1(void)
{
    set_description("Lowercase letters"); c = 'a'; 
    ft_res = ft_toupper(c); res = toupper(c);
    check_is_equal(INT, ft_res, res);
}

void	test2(void)
{
    set_description("Uppercase letters"); c = 'Z'; 
    ft_res = ft_toupper(c); res = toupper(c);
    check_is_equal(INT, ft_res, res);
}

void	test3(void)
{
	set_description("Non-alphabetic characters"); c = '1'; 
    ft_res = ft_toupper(c); res = toupper(c);
    check_is_equal(INT, ft_res, res);
}

void	test4(void)
{
	set_description("Negative value"); c = -1; 
    ft_res = ft_toupper(c); res = toupper(c);
    check_is_equal(INT, ft_res, res);
}

int main(void)
{
	handle(&test1);
	handle(&test2);
	handle(&test3);
	handle(&test4);

    return (0);
}
