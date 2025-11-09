/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:03:23 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:06:04 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void *memmove(void *dst, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char	*ft_res, *res;
	char	*ft_to_free, *to_free;
	int		status;
	pid_t	pid;
	size_t	len;

	// test 1
	set_description("Basic copy"); len = 12; 
	ft_to_free = ft_res = malloc(len); to_free = res = malloc(len);
	memset(ft_res, 0, len); memset(res, 0, len);
	memcpy(ft_res, "Hello world", 12); memcpy(res, "Hello world", 12);
	ft_res = ft_memmove(ft_res + 2, ft_res, 10); res = memmove(res + 2, res, 10);
	check_is_equal(STR, ft_res, res);
	free(ft_to_free); free(to_free);

	// test 2
	set_description("Exact overlap"); len = 12; 
	ft_to_free = ft_res = malloc(len); to_free = res = malloc(len);
	memset(ft_res, 0, len); memset(res, 0, len);
	memcpy(ft_res, "Hello world", 12); memcpy(res, "Hello world", 12);
	ft_res = ft_memmove(ft_res, ft_res, 12); res = memmove(res, res, 12);
	check_is_equal(STR, ft_res, res);
	free(ft_to_free); free(to_free);

	// test 3
	set_description("NULL pointer test [segfault]"); 
	pid = fork();
	if (pid == 0)
	{
		(void)ft_memmove(NULL, NULL, 5);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	return (0);
}
