/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:08:55 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 17:36:56 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((uint8_t *)s)[n] = (uint8_t)c;
	return (s);
}

size_t	ft_strlen(char const *s)
{
	size_t	i = -1;

	while (s[++i])
		;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	while (i + 1 < dstsize && src[i])
		*dst++ = src[i++];
	if (dstsize)
		*dst = 0;
	src_len = -1;
	while (src[++src_len])
		;
	return (src_len);
}

size_t strlcat(char *dest, const char *src, size_t size);

int	main(void)
{
	size_t	ft_res, res, size;
	char	*src, *dest, *ft_dest;
    int		status;
	pid_t	pid;

	// test 1
	set_description("Test regular string [return value]");
	ft_dest = malloc(10); dest = malloc(10);
	src = "Hello world"; size = 5;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);

	// test 2
	set_description("Test regular string [strings]");
	check_is_equal(STR, ft_dest, dest);
	free(ft_dest); free(dest);

	// test 3
	set_description("Empty dest");
	ft_dest = "";
	src = "Hello world"; size = 5;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strlcat(ft_dest, src, size);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");
	
	// test 4
	set_description("Size 0");
	ft_dest = malloc(10); dest = malloc(10);
	src = "Hello world"; size = 0;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);
	free(ft_dest); free(dest);

	// test 5
	set_description("Empty src");
	ft_dest = malloc(10); dest = malloc(10);
	src = ""; size = 0;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);
	free(ft_dest); free(dest);

	// test 6
	set_description("Size 1");
	ft_dest = malloc(10); dest = malloc(10);
	src = "Hello world"; size = 1;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);
	free(ft_dest); free(dest);

	// test 7
	set_description("NULL dest");
	ft_dest = NULL;
	src = "Hello world"; size = 5;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strlcat(ft_dest, src, size);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");

	// test 8
	set_description("NULL src");
	ft_dest = malloc(8);
	src = NULL; size = 5;
	pid = fork();
	if (pid == 0)
	{
		(void)ft_strlcat(ft_dest, src, size);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		check_is_equal(STR, "Segfault", "Segfault");
	else
		check_is_equal(STR, "No Segfault", "Segfault");
	free(ft_dest);

	// test 9
	set_description("Dest already has content [return value]");
	ft_dest = malloc(20); dest = malloc(20);
	ft_strlcpy(ft_dest, "Hi ", 4); ft_strlcpy(dest, "Hi ", 4);
	src = "there!"; size = 20;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);

	// test 10
	set_description("Dest already has content [strings]");
	check_is_equal(STR, ft_dest, dest);
	free(ft_dest); free(dest);

	// test 11
	set_description("Truncation when size < dest len [return value]");
	ft_dest = malloc(10); dest = malloc(10);
	ft_strlcpy(ft_dest, "abcdef", 7); ft_strlcpy(dest, "abcdef", 7);
	src = "12345"; size = 3;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);

	// test 12
	set_description("Truncation when size < dest len [strings]");
	check_is_equal(STR, ft_dest, dest);
	free(ft_dest); free(dest);

	// test 13
	set_description("Dest too small [return value]");
	ft_dest = malloc(12); dest = malloc(12);
	ft_strlcpy(ft_dest, "abc", 4); ft_strlcpy(dest, "abc", 4);
	src = "defgh"; size = ft_strlen("abc") + ft_strlen("defgh");
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);

	// test 14
	set_description("Dest too small [strings]");
	check_is_equal(STR, ft_dest, dest);
	free(ft_dest); free(dest);

	// test 15
	set_description("Long src [return value]");
	ft_dest = malloc(50); dest = malloc(50);
	ft_memset(ft_dest, 0, 50); ft_memset(dest, 0, 50);
	ft_strlcpy(ft_dest, "short", 6); ft_strlcpy(dest, "short", 6);
	src = malloc(1001); ft_memset(src, 'A', 1000); src[1000] = '\0'; size = 50;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);

	// test 16
	set_description("Long src [strings]");
	check_is_equal(STR, ft_dest, dest);
	free(ft_dest); free(dest); free((void*)src);

	// test 17
	set_description("Empty dest with size 1 [return value]");
	ft_dest = malloc(10); dest = malloc(10);
	ft_dest[0] = '\0'; dest[0] = '\0';
	src = "Hello world"; size = 1;
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);

	// test 18
	set_description("Empty dest with size 1 [strings]");
	check_is_equal(STR, ft_dest, dest);
	free(ft_dest); free(dest);

	// test 19
	set_description("dest size == dest len [return value]");
	ft_dest = malloc(10); dest = malloc(10);
	ft_strlcpy(ft_dest, "abc", 4); ft_strlcpy(dest, "abc", 4);
	src = "12345"; size = ft_strlen("abc");
	ft_res = ft_strlcat(ft_dest, src, size); res = strlcat(dest, src, size);
	check_is_equal(SIZE_T, ft_res, res);

	// test 20
	set_description("dest size == dest len [strings]");
	check_is_equal(STR, ft_dest, dest);
	free(ft_dest); free(dest);

	return (0);
}
