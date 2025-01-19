/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:08:59 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/18 21:07:26 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing_internal.h"

static int	split_by_operators(const char *s, char ***p_ss)
{
	int			sz;
	t_delims	op_arr;

	sz = 0;
	if (s == NULL)
		return (1);
	op_arr = create_operator_array();
	if (op_arr.error)
		return (1);
	*p_ss = ft_split_str(s, op_arr, &sz);
	if (*p_ss == NULL)
		return (cleanup(&op_arr, *p_ss, 2));
	return (cleanup(&op_arr, 0, 0));
}

int	tokenize_cmd(const char *s, char ***p_ss)
{
	int	ret;

	ret = if_empty_string(s, p_ss);
	if (ret != 0)
		return (ret);
	if (split_by_operators(s, p_ss) != 0)
		return (1);
	return (0);
}
