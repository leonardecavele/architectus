/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:09:58 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/09 21:32:24 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "../libft.h"

// colors
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[2;32m"

typedef enum e_type
{
	INT,
	SIZE_T,
	PTR,
	CHAR,
	STR
}	t_type;

# define SEGFAULT true
# define NO_SEGFAULT false

void	display_description();
void	set_display(const char *, const char *);
void	set_description(const char *description);

void	handle(void (*f)(void));
void	handle_sigsegv(const char *description, void (*f)(void), bool must_segfault);
void	check_is_equal(t_type type, ...);

#endif
