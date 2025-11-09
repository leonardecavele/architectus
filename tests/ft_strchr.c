/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:45:25 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 17:57:21 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *strchr(const char *s, int c);

int	main(void)
{
	char	*ft_res, *res, *s;
	int		status;
	pid_t	pid;

	// test 1
	set_description("Basic match [return value]");
	s = "Hello world";
	ft_res = ft_strchr(s, 'o'); res = strchr(s, 'o');
	check_is_equal(STR, ft_res, res);

	// test 2
	set_description("Basic match [string]");
	check_is_equal(STR, ft_res, res);

	// test 3
	set_description("No match [return value]");
	s = "abcdef";
	ft_res = ft_strchr(s, 'z'); res = strchr(s, 'z');
	check_is_equal(STR, ft_res, res);

	// test 4
	set_description("No match [string]");
	check_is_equal(STR, ft_res, res);

	// test 5
	set_description("Match with first character [return value]");
	s = "abc";
	ft_res = ft_strchr(s, 'a'); res = strchr(s, 'a');
	check_is_equal(STR, ft_res, res);

	// test 6
	set_description("Match with first character [string]");
	check_is_equal(STR, ft_res, res);

	// test 7
	set_description("Match with last character [return value]");
	s = "abc";
	ft_res = ft_strchr(s, 'c'); res = strchr(s, 'c');
	check_is_equal(STR, ft_res, res);

	// test 8
	set_description("Match with last character [string]");
	check_is_equal(STR, ft_res, res);

	// test 9
	set_description("Search for '\\0' [return value]");
	s = "abc";
	ft_res = ft_strchr(s, '\0'); res = strchr(s, '\0');
	check_is_equal(STR, ft_res, res);

	// test 10
	set_description("Search for '\\0' [string]");
	check_is_equal(STR, ft_res, res);

	// test 11
	set_description("Empty string [return value]");
	s = "";
	ft_res = ft_strchr(s, 'a'); res = strchr(s, 'a');
	check_is_equal(STR, ft_res, res);

	// test 12
	set_description("Empty string [string]");
	check_is_equal(STR, ft_res, res);

	// test 13
	set_description("NULL pointer [segfault]");
	s = NULL;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strchr(s, 'a');
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	return (0);
}
