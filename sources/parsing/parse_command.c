/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:11:49 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/02 18:44:28 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_processing.h"

static char	**split_excluding_quotes(char **result, char **s)
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
		temp_split = ft_split_skip_delim(s[i++], ' ', '"', &sz);
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

static void	calculate_spaces(char **ss, int *total_sz)
{
	int		i;
	int		sz;
	char	**tok_space;

	i = 0;
	sz = 0;
	while (ss[i] != NULL)
	{
		tok_space = ft_split_skip_delim(ss[i], ' ', '"', &sz);
		if (tok_space == NULL)
			return ;
		*total_sz += sz;
		i++;
		ft_free_ss_sz_null((void *)&tok_space, sz);
	}
	return ;
}

char	**split_by_space(char **ss)
{
	int		total_sz;
	char	**result;

	total_sz = 0;
	calculate_spaces(ss, &total_sz);
	result = ft_calloc_if((total_sz + 1) * sizeof(char *), 1);
	if (!result)
		return (NULL);
	result = split_excluding_quotes(result, ss);
	return (result);
}

char	**split_by_operators(const char *s, t_delims *arr, int *sz)
{
	char	**tok_oper;

	tok_oper = ft_split_str(s, arr, sz);
	if (!tok_oper)
		return (NULL);
	return (tok_oper);
}

char	**parse_command(const char *s)
{
	int			sz;
	char		**tok_oper;
	char		**tok_space;
	t_delims	op_arr;

	sz = 0;
	op_arr = create_operator_array();
	if (op_arr.error)
		return (NULL);
	tok_oper = split_by_operators(s, &op_arr, &sz);
	if (tok_oper == NULL || tok_oper[0] == NULL)
	{
		cleanup(&op_arr, &tok_oper, sz);
		return (NULL);
	}
	tok_space = split_by_space(tok_oper);
	if (!tok_space)
	{
		cleanup(&op_arr, &tok_oper, sz);
		return (NULL);
	}
	cleanup(&op_arr, &tok_oper, sz);
	return (tok_space);
}
