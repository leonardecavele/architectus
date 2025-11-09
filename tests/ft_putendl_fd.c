/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:27:16 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:30:31 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    int pipefd[2];
    char buf[100];

    // test 1
    set_description("Basic string"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putendl_fd("Hello", pipefd[1]);
    int r = read(pipefd[0], buf, 6); // "Hello\n"
	if (buf[r - 1] == '\n')
	{
		buf[r - 1] = '\\';
		buf[r] = 'n';
		buf[r + 1] = '\0';
	}
    check_is_equal(STR, buf, "Hello\\n");
    close(pipefd[0]); close(pipefd[1]);

    return (0);
}
