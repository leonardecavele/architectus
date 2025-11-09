/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:48:46 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 23:50:38 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "tester.h"

static void _increment(void *content)
{
    if (content)
        (*(char *)content)++;
}

void test1(void)
{
    t_list *node1 = ft_lstnew(strdup("a"));
    t_list *node2 = ft_lstnew(strdup("b"));
    t_list *node3 = ft_lstnew(strdup("c"));
    node1->next = node2;
    node2->next = node3;

    set_description("Apply a function to all elements of the list");
    ft_lstiter(node1, _increment);

    set_description("First node content should be modified from 'a' to 'b'");
    check_is_equal(STR, node1->content, "b");

    set_description("Second node content should be modified from 'b' to 'c'");
    check_is_equal(STR, node2->content, "c");

    set_description("Third node content should be modified from 'c' to 'd'");
    check_is_equal(STR, node3->content, "d");

    free(node1->content);
    free(node2->content);
    free(node3->content);
    free(node3);
    free(node2);
    free(node1);
}

void test2(void)
{
    t_list *list = NULL;

    set_description("Calling ft_lstiter with NULL list should not crash");
    ft_lstiter(list, _increment);
}

void test3(void)
{
    t_list *list = ft_lstnew(strdup("test"));

    set_description("Calling ft_lstiter with NULL function pointer should segfault (undefined behavior)");
    ft_lstiter(list, NULL);

    free(list->content);
    free(list);
}

int main(void)
{
    handle(&test1);
    handle_sigsegv("Calling ft_lstiter with NULL list should NOT segfault", &test2, NO_SEGFAULT);
    handle_sigsegv("Calling ft_lstiter with NULL function pointer should segfault", &test3, SEGFAULT);
}
