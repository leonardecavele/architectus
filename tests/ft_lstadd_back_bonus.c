/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:41:05 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 23:46:02 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tester.h"

void    test1(void)
{
    t_list *list = ft_lstnew("hello");
    t_list *node = ft_lstnew("world");

    set_description("Add a new node at the back. The old last node's next must point to the new node.");
    ft_lstadd_back(&list, node);
    check_is_equal(PTR, list->next, node);

    set_description("Verify the new last node contains the correct value.");
    check_is_equal(STR, list->next->content, "world");

    free(list->next);
    free(list);
}

void    test2(void)
{
    t_list  *list = ft_lstnew("first");

    set_description("Passing NULL as list pointer should segfault.");
    ft_lstadd_back(NULL, list);
    free(list);
}

void    test3(void)
{
    t_list  *list = ft_lstnew("hello");

    set_description("Passing NULL as node to add should not change the list.");
    ft_lstadd_back(&list, NULL);
    check_is_equal(PTR, list->next, NULL);

    free(list);
}

void    test4(void)
{
    t_list *list = NULL;
    t_list *node = ft_lstnew("single");

    set_description("Add a node to an empty list.");
    ft_lstadd_back(&list, node);
    check_is_equal(PTR, list, node);
    
	set_description("Check if node has next set to null.");
    check_is_equal(PTR, list->next, NULL);

    free(list);
}

int     main(void)
{
    handle(&test1);
    handle_sigsegv("Check if NULL list segfault", &test2, SEGFAULT);
    handle_sigsegv("Check if NULL node segfault", &test3, NO_SEGFAULT);
    handle(&test4);
}
