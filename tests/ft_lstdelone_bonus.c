/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:16:14 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 23:24:48 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tester.h"

void del_free(void *content)
{
    free(content);
}

void test1(void)
{
    t_list *node;

    node = ft_lstnew(malloc(10));
    ft_lstdelone(node, del_free);
}

void test2(void)
{
    t_list *node;

    node = ft_lstnew(NULL);
    ft_lstdelone(node, del_free);
}

void test3(void)
{
	ft_lstdelone(NULL, del_free);
}

int main(void)
{
    handle_sigsegv("Check frees node and content", &test1, NO_SEGFAULT);
    handle_sigsegv("Check free node with NULL content", &test2, NO_SEGFAULT);
    handle_sigsegv("Check NULL node should NOT segfault", test3, NO_SEGFAULT);
}
