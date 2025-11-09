/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:28:41 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 23:37:51 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tester.h"

static void del(void *content)
{
    free(content);
}

void test1(void)
{
    t_list *list = NULL;
    ft_lstclear(&list, del);
}

void test2(void)
{
    t_list *list;
    list = ft_lstnew(malloc(10));
    ft_lstclear(&list, del);
}

void test3(void)
{
    t_list *list;
    list = ft_lstnew(malloc(10));
    list->next = ft_lstnew(malloc(20));
    list->next->next = ft_lstnew(malloc(30));
    ft_lstclear(&list, del);
}

void test4(void)
{
    t_list *list;
    list = ft_lstnew(NULL);
    list->next = ft_lstnew(NULL);
    ft_lstclear(&list, del);
}

void test5(void)
{
    ft_lstclear(NULL, del);
}

void test6(void)
{
    t_list *list;
    list = ft_lstnew(malloc(10));
    list->next = ft_lstnew(malloc(20));
    ft_lstclear(&list, NULL);
}

int main(void)
{
    handle_sigsegv("Clearing an empty list should not crash", &test1, NO_SEGFAULT);
    handle_sigsegv("Clearing a single-node list should free it", &test2, NO_SEGFAULT);
    handle_sigsegv("Clearing multiple nodes should free all", &test3, NO_SEGFAULT);
    handle_sigsegv("Clearing a list with NULL content should not segfault", &test4, NO_SEGFAULT);
    handle_sigsegv("Calling ft_lstclear with NULL pointer should not segfault", &test5, NO_SEGFAULT);
    handle_sigsegv("Calling ft_lstclear with NULL del function should segfault", &test6, SEGFAULT);
}
