/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:08:59 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/22 12:23:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_processing.h"

static char	**split_excluding_quotes(char **result, t_delims *arr, char **s)
{
	int		i;
	int		j;
	int		sz;
	int		res_i;
	char	**temp_split;

	i = 0;
	res_i = 0;
	while (s[i] != NULL)
	{
		temp_split = ft_split_skip_delim(s[i++], arr, '"', &sz);
		j = 0;
		while (j < sz)
		{
			result[res_i++] = ft_strdup(temp_split[j++]);
		}
		ft_free_ss_sz_null((void *)&(temp_split), sz);
	}
	result[res_i] = NULL;
	return (result);
}

static void	count_sps_tabs(char **ss, int *total_sz, t_delims *arr)
{
	int		i;
	int		sz;
	char	**tok_space;

	i = 0;
	sz = 0;
	while (ss[i] != NULL)
	{
		tok_space = ft_split_skip_delim(ss[i], arr, '"', &sz);
		if (tok_space == NULL)
			return ;
		*total_sz += sz;
		i++;
		ft_free_ss_sz_null((void *)&tok_space, sz);
	}
	return ;
}

char	**split_by_spcs_tabs(char **ss, t_delims *arr)
{
	int			total_sz;
	char		**result;

	total_sz = 0;
	count_sps_tabs(ss, &total_sz, arr);
	result = ft_calloc_if((total_sz + 1) * sizeof(char *), 1);
	if (!result)
		return (NULL);
	result = split_excluding_quotes(result, arr, ss);
	return (result);
}

char	**split_by_operators(const char *s, int *sz)
{
	char	**tok_oper;
	t_delims	op_arr;
	
	op_arr = create_operator_array();
	if (op_arr.error)
		return (NULL);
	tok_oper = ft_split_str(s, &op_arr, sz);
	if (!tok_oper)
	{
		cleanup(&op_arr, 0, *sz);
		return (NULL);
	}
	cleanup(&op_arr, 0, *sz);
	return (tok_oper);
}

char	**tokenize_cmd(const char *s)
{
	int			sz;
	char		**tok_oper;
	char		**tok_space;
	t_delims	delim_arr;

	sz = 0;
	tok_oper = split_by_operators(s, &sz);
	if (tok_oper == NULL || tok_oper[0] == NULL)
	{
		cleanup(0, &tok_oper, sz);
		return (NULL);
	}

	
	delim_arr = create_delim_arr();
	if (delim_arr.error)
	{
		cleanup(0, &tok_oper, sz);
	}
	tok_space = split_by_spcs_tabs(tok_oper, &delim_arr);
	if (!tok_space)
	{
		cleanup(0, &tok_oper, sz);
		return (NULL);
	}
	cleanup(0, &tok_oper, sz);
	return (tok_space);
}
