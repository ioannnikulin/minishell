/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:49:54 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 21:31:34 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing_internal.h"

int	count_tokens(char **ss, t_delims arr, t_skip_chars ex_arr, int *t_sz)
{
	int				i;
	int				sz;

	i = 0;
	sz = 0;
	while (ss[i] != NULL)
	{
		sz = count_words_skip_delim(ss[i], arr, ex_arr);
		*t_sz += sz;
		i++;
	}
	if (*t_sz == 0)
		*t_sz = 1;
	return (0);
}

int	cleanup(t_delims *arr, t_skip_chars *ex_arr, char **ss, int retval)
{
	if (arr != NULL)
	{
		ft_free_delims_arr(arr);
	}
	if (ss != NULL && *ss != NULL)
	{
		ft_free_ss_uptonull((void **)ss);
	}
	if (ex_arr != NULL)
	{
		ft_free_delim_c(ex_arr);
	}
	return (retval);
}
