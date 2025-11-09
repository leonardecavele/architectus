/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:21:24 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:22:27 by ldecavel         ###   ########.fr       */
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
    char buf;

    // test 1
    set_description("Write single char"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putchar_fd('A', pipefd[1]);
    read(pipefd[0], &buf, 1);
    check_is_equal(CHAR, buf, 'A');
    close(pipefd[0]); close(pipefd[1]);

    // test 2
    set_description("Write multiple chars"); 
    if (pipe(pipefd) == -1)
        exit(1);
    ft_putchar_fd('H', pipefd[1]);
    ft_putchar_fd('i', pipefd[1]);
    char out[2];
    read(pipefd[0], out, 2);
    check_is_equal(CHAR, out[0], 'H');
    check_is_equal(CHAR, out[1], 'i');
    close(pipefd[0]); close(pipefd[1]);

    return (0);
}
