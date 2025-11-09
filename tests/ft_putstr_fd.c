/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:23:31 by ldecavel          #+#    #+#             */
/*   Updated: 2025/11/09 19:26:59 by ldecavel         ###   ########.fr       */
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
    ft_putstr_fd("Hello", pipefd[1]);
    read(pipefd[0], buf, 5);
    buf[5] = '\0';
    check_is_equal(STR, buf, "Hello");
    close(pipefd[0]); close(pipefd[1]);

    return (0);
}
