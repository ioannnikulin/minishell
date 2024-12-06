/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:49:54 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/06 18:19:39 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_processing.h"

t_delims	create_operator_array(void)
{
	t_delims	op_arr;

	op_arr.count = 10;
	op_arr.error = 0;
	op_arr.delims = ft_calloc_if(sizeof(t_delim) * op_arr.count, 1);
	if (op_arr.delims == NULL)
	{
		op_arr.error = 1;
		return (op_arr);
	}
	op_arr.delims[0].delim = ">>";
	op_arr.delims[1].delim = ">";
	op_arr.delims[2].delim = "<<";
	op_arr.delims[3].delim = "<";
	op_arr.delims[4].delim = "||";
	op_arr.delims[5].delim = ")";
	op_arr.delims[6].delim = "&&";
	op_arr.delims[7].delim = "&";
	op_arr.delims[8].delim = "(";
	op_arr.delims[9].delim = "|";
	return (op_arr);
}

t_delims	create_delim_arr(void)
{
	t_delims	delim_array;

	delim_array.count = 2;
	delim_array.error = 0;
	delim_array.delims = ft_calloc_if(sizeof(t_delim) * delim_array.count, 1);
	if (delim_array.delims == NULL)
	{
		delim_array.error = 1;
		return (delim_array);
	}
	delim_array.delims[0].delim = " ";
	delim_array.delims[1].delim = "\t";
	return (delim_array);
}

int	count_tokens(char **ss, t_delims arr, int *t_sz)
{
	int		i;
	int		sz;

	i = 0;
	sz = 0;
	while (ss[i] != NULL)
	{
		sz = count_words_skip_delim(ss[i], arr, '"');
		*t_sz += sz;
		i++;
	}
	if (*t_sz == 0)
		return (1);
	return (0);
}

int	cleanup(t_delims *arr, char **ss, int retval)
{
	if (arr != NULL)
	{
		ft_free_delims_arr(arr);
	}
	if (ss != NULL && *ss != NULL)
	{
		ft_free_ss_uptonull((void **)ss);
	}
	return (retval);
}
