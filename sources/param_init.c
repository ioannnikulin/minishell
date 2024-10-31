/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 23:01:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	param_get_cur_dir(t_param *param)
{
	int		sz;
	char	*tgt;
	t_dlist	*node;

	sz = 32;
	tgt = 0;
	while (!tgt || !tgt[0])
	{
		free(tgt);
		tgt = ft_calloc_if(sizeof(char) * sz, 1);
		if (!tgt)
			return (1);
		getcwd(tgt, sz);
		sz <<= 1;
		if (sz < 0)
			return (2);
	}
	node = ft_dlist_new(tgt);
	if (!node)
		return (3);
	ft_dlist_add_front(&param->envvar_path_head, node);
	return (0);
}

t_param	*param_init(void)
{
	t_param	*param;

	param = ft_calloc_if(sizeof(t_param), 1);
	if (!param)
		return (0);
	if (param_get_cur_dir(param) || param_get_envvars(param))
		return (0);
	param->debug_output_level = 0;
	return (param);
}
