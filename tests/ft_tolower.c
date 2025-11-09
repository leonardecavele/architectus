/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:08:38 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:09:10 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <ctype.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int tolower(int c);

int main(void)
{
    int ft_res, res;
    int c;

    // test 1
    set_description("Lowercase letters"); c = 'a'; 
    ft_res = ft_tolower(c); res = tolower(c);
    check_is_equal(INT, ft_res, res);

    // test 2
    set_description("Uppercase letters"); c = 'Z'; 
    ft_res = ft_tolower(c); res = tolower(c);
    check_is_equal(INT, ft_res, res);

    // test 3
    set_description("Non-alphabetic characters"); c = '1'; 
    ft_res = ft_tolower(c); res = tolower(c);
    check_is_equal(INT, ft_res, res);

    // test 4
    set_description("Negative value"); c = -1; 
    ft_res = ft_tolower(c); res = tolower(c);
    check_is_equal(INT, ft_res, res);

    return (0);
}
