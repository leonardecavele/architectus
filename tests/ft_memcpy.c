/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:56:41 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:01:25 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *s, int c, size_t n);

int	main(void)
{
	char	*ft_res, *res, *src;
	int		status;
	pid_t	pid;
	size_t	len;

	// test 1
	set_description("Basic copy"); src = "Hello world"; len = 12; 
	ft_res = malloc(len); res = malloc(len);
	memset(ft_res, 0, len); memset(res, 0, len);
	ft_res = ft_memcpy(ft_res, src, len); res = memcpy(res, src, len);
	check_is_equal(STR, ft_res, res);
	free(ft_res); free(res);

	// test 2
	set_description("Empty copy"); src = ""; len = 1; 
	ft_res = malloc(len); res = malloc(len);
	memset(ft_res, 0, len); memset(res, 0, len);
	ft_res = ft_memcpy(ft_res, src, len); res = memcpy(res, src, len);
	check_is_equal(STR, ft_res, res);
	free(ft_res); free(res);

	// test 3
	set_description("NULL pointer test [segfault]"); 
	pid = fork();
	if (pid == 0)
	{
		(void)ft_memcpy(NULL, NULL, 5);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	return (0);
}
