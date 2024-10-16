/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:11:49 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/16 10:58:02 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_delims create_operator_array()
{
	t_delims delim_array;
	delim_array.count = 10;
	delim_array.error = 0;
	delim_array.delims = (t_delim *)malloc(sizeof(t_delim) * delim_array.count);
	if (delim_array.delims == NULL)
	{
		delim_array.error = 1;
		return (delim_array);
	}
	delim_array.delims[0].delim = ">>";
	delim_array.delims[1].delim = ">";
	delim_array.delims[2].delim = "<<";
	delim_array.delims[3].delim = "<";
	delim_array.delims[4].delim = "||";
	delim_array.delims[5].delim = ")";
	delim_array.delims[6].delim = "&&";
	delim_array.delims[7].delim = "&";
	delim_array.delims[8].delim = "(";
	delim_array.delims[9].delim = "|";
	return (delim_array);
}

char    **parse_command(char *s)
{
    t_delims	op_arr;
    char	    **tok_oper;
	char	    **tok_space;
	int 	    sz_1;
	int         sz_2;

    op_arr = create_operator_array();
    if (op_arr.error)
        return (NULL);
    tok_oper = ft_split_buf(s, (void *)&op_arr, &sz_1);
    if (!tok_oper)
    {
        free(op_arr.delims);
        return (NULL);
    }
	tok_space = ft_split(tok_oper, ' ', &sz_2);
    if (!tok_space) 
    {
        free(op_arr.delims);
        free(tok_oper);
        return (NULL);
    }
    return (tok_space);
}