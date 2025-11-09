/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:09:57 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:10:11 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n);

int main(void)
{
    int ft_res, res;
    int status;
    pid_t pid;
    const char *s1, *s2;
    size_t n;

    // test 1
    set_description("Equal buffers"); s1 = "abcdef"; s2 = "abcdef"; n = 6;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);

    // test 2
    set_description("Different buffers"); s1 = "abcdef"; s2 = "abcdez"; n = 6;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);

    // test 3
    set_description("Empty buffers"); s1 = ""; s2 = ""; n = 0;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);

    // test 4
    set_description("Partial comparison"); s1 = "abcdef"; s2 = "abcdez"; n = 3;
    ft_res = ft_memcmp(s1, s2, n); res = memcmp(s1, s2, n);
    check_is_equal(INT, ft_res, res);

    // test 5
    set_description("NULL pointers [segfault]");
    pid = fork();
    if (pid == 0)
    {
        (void)ft_memcmp(NULL, NULL, 5);
        exit(0);
    }
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
        check_is_equal(STR, "Segfault", "Segfault");
    else
        check_is_equal(STR, "No Segfault", "Segfault");

    return (0);
}
