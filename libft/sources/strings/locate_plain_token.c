/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_plain_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:25 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/12 15:13:20 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

/*return 1 if its not a plain token*/
int	locate_plain_token(const char *s, t_delims arr, size_t *len)
{
	size_t	sz;

	sz = 0;
	while (*s && !find_delimiter(s, arr, &sz) && *s != '\'')
	{
		s++;
		(*len)++;
	}
	if (*len == 0)
		return (0);
	return (1);
}
