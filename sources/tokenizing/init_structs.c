/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:30:21 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/09 13:30:39 by taretiuk         ###   ########.fr       */
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

int	create_ex_arr(t_skip_chars *ex_arr)
{
	ex_arr->count = 2;
	ex_arr->error = 0;
	ex_arr->exs = ft_calloc_if(sizeof(t_skip_chars) * ex_arr->count, 1);
	if (ex_arr->exs == NULL)
	{
		ex_arr->error = 1;
		return (ex_arr->error);
	}
	ex_arr->exs[0].ex = '"';
	ex_arr->exs[1].ex = '\'';
	return (0);
}
