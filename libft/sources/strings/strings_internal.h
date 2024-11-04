/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:40:11 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/04 05:42:37 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_INTERNAL_H
# define STRINGS_INTERNAL_H

# include "../libft/libft.h"
# include "strings.h"
# include "../memory/memory.h"

int		find_delimiter(const char *s, t_delims *array, size_t *op_len);
int		extract_plain_token(char **res, const char **s,
			t_delims *array, int cwi);
int		extract_delimiter(char **res, const char **s,
			size_t op_len, int cwi);
int		copy_word(char **res, const char *from, int length);
bool	is_in_quotes(const char **p, const char ex, int *in_quotes);
#endif
