/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:40:11 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/23 15:47:20 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_INTERNAL_H
# define STRINGS_INTERNAL_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "strings.h"
# include "../memory/memory.h"

int		find_delimiter(const char *s, t_delims *array, size_t *op_len);
int		extract_plain_token(char **res, const char **s,
			t_delims *array, int cwi);
int		extract_delimiter(char **res, const char **s,
			size_t op_len, int cwi);
void	copy_word(char **res, char **from, const char *charset,
			const char ex);
bool	is_in_quotes(char **p, const char ex, int *in_quotes);
#endif
