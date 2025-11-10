/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:41:05 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/10 14:56:22 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(struct s_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}

static	t_list	*list, *node;

void    test1(void)
{
    list = ft_lstnew("hello");
    node = ft_lstnew("world");

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
    list = ft_lstnew("first");

    ft_lstadd_back(NULL, list);
    free(list);
}

void    test3(void)
{
    list = ft_lstnew("hello");

    ft_lstadd_back(&list, NULL);
    check_is_equal(PTR, list->next, NULL);

    free(list);
}

void    test4(void)
{
    list = NULL;
    node = ft_lstnew("single");

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
    handle_sigsegv("Check if NULL list [no segfault]", &test2, NO_SEGFAULT);
    handle_sigsegv("Check if NULL node [no segfault]", &test3, NO_SEGFAULT);
    handle(&test4);
	return (0);
}
