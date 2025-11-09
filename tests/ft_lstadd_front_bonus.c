/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 21:42:47 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 22:21:24 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test1(void)
{
    t_list *list = ft_lstnew("hello");
    t_list *node = ft_lstnew("world");
	t_list *previous_first = list;

    set_description("Add a new node at the front. It's next must point to the old first node.");
    ft_lstadd_front(&list, node);
    check_is_equal(PTR, list->next, previous_first);

    set_description("Verify the next node contains the correct value.");
    check_is_equal(STR, list->next->content, "hello");

    free(list->next);
    free(list);
}

void	test2(void)
{
	t_list	*list = ft_lstnew("hello");
	ft_lstadd_front(NULL, list);
	free(list);
}

void	test3(void)
{
	t_list	*list;
	list = ft_lstnew("hello");
	ft_lstadd_front(&list, NULL);
	free(list);
}

void test4(void)
{
    t_list *list = NULL;
    t_list *node = ft_lstnew("single");

    set_description("Add a node to an empty list.");
    ft_lstadd_front(&list, node);
    check_is_equal(PTR, list, node);
    check_is_equal(PTR, list->next, NULL);

    free(list);
}

int	main(void)
{
	// test 1
	handle(&test1);
	
	// test 2
	handle_sigsegv("Check if NULL list Segfault", &test2, SEGFAULT);
	
	// test 3
	handle_sigsegv("Check if NULL node Segfault", &test3, SEGFAULT);
	
	// test 4
	handle(&test4);
}
