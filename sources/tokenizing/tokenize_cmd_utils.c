/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:49:54 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/22 09:09:30 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_processing.h"

t_delims	create_operator_array(void)
{
	t_delims	operator_array;

	operator_array.count = 10;
	operator_array.error = 0;
	operator_array.delims = ft_calloc_if(sizeof(t_delim) * operator_array.count, 1);
	if (operator_array.delims == NULL)
	{
		operator_array.error = 1;
		return (operator_array);
	}
	operator_array.delims[0].delim = ">>";
	operator_array.delims[1].delim = ">";
	operator_array.delims[2].delim = "<<";
	operator_array.delims[3].delim = "<";
	operator_array.delims[4].delim = "||";
	operator_array.delims[5].delim = ")";
	operator_array.delims[6].delim = "&&";
	operator_array.delims[7].delim = "&";
	operator_array.delims[8].delim = "(";
	operator_array.delims[9].delim = "|";
	return (operator_array);
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

void	cleanup(t_delims *op_arr, char ***tok_oper, int sz)
{
	if (op_arr != NULL)
	{
		ft_free_delims_arr(op_arr);
	}
	if (tok_oper != NULL && *tok_oper != NULL)
	{
		ft_free_ss_sz_null((void ***)tok_oper, sz);
	}
}
