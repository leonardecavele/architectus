/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:09:58 by nlallema          #+#    #+#             */
/*   Updated: 2025/11/08 15:41:33 by nlallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdarg.h>
# include "../libft.h"

typedef enum e_vtype {
  T_INT,
  T_CHAR,
  T_STR
}      t_vtype;

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[2;32m"

void	set_display(const char *, const char *);
void	set_description(const char *description);

void	check_is_equal(t_vtype type, ...);

#endif
