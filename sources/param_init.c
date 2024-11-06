/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 23:55:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cwd(void)
{
	int		sz;
	char	*tgt;

	sz = 32;
	tgt = 0;
	while (!tgt || !tgt[0])
	{
		free(tgt);
		tgt = ft_calloc_if(sizeof(char) * sz, 1);
		if (!tgt)
			return (0);
		getcwd(tgt, sz);
		sz <<= 1;
		if (sz < 0)
		{
			free(tgt);
			return (0);
		}
	}
	return (tgt);
}

int	param_get_cur_dir(t_param *param)
{
	char	*tgt;
	t_dlist	*node;

	tgt = cwd();
	if (!tgt)
		return (1);
	node = ft_dlist_new(tgt);
	if (!node)
	{
		free(tgt);
		return (2);
	}
	ft_dlist_add_front(&param->envvar_path_head, node);
	return (0);
}

t_param	*param_alloc(void)
{
	t_param	*param;

	param = ft_calloc_if(sizeof(t_param), 1);
	if (!param)
		return (0);
	param->opts.debug_output_level = 0;
	return (param);
}

int	param_init(t_param *param)
{
	param->envvars = ft_mapss_init();
	if (!param->envvars)
		return (1);
	return (0);
}
