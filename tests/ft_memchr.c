/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:10:38 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:15:57 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void *memchr(const void *s, int c, size_t n);

int main(void)
{
    unsigned char	*ft_res, *res;
	char			*s;
    int				status;
    pid_t			pid;
    size_t			n;
    int				c;

    // test 1
    set_description("Basic match"); s = "abcdef"; c = 'c'; n = 6;
    ft_res = ft_memchr((char *)s, c, n); res = memchr((char *)s, c, n);
    check_is_equal(STR, ft_res, res);

    // test 2
    set_description("No match"); s = "abcdef"; c = 'z'; n = 6;
    ft_res = ft_memchr((char *)s, c, n); res = memchr((char *)s, c, n);
    check_is_equal(STR, ft_res, res);

    // test 3
    set_description("Match first byte"); s = "abcdef"; c = 'a'; n = 6;
    ft_res = ft_memchr((char *)s, c, n); res = memchr((char *)s, c, n);
    check_is_equal(STR, ft_res, res);

    // test 4
    set_description("Match last byte"); s = "abcdef"; c = 'f'; n = 6;
    ft_res = ft_memchr((char *)s, c, n); res = memchr((char *)s, c, n);
    check_is_equal(STR, ft_res, res);

    // test 5
    set_description("Zero length"); s = "abcdef"; c = 'a'; n = 0;
    ft_res = ft_memchr((char *)s, c, n); res = memchr((char *)s, c, n);
    check_is_equal(STR, ft_res, res);

    // test 6
    set_description("NULL pointer [segfault]");
    pid = fork();
    if (pid == 0)
    {
        (void)ft_memchr(NULL, 'a', 5);
        exit(0);
    }
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
        check_is_equal(STR, "Segfault", "Segfault");
    else
        check_is_equal(STR, "No Segfault", "Segfault");

    return (0);
}
