/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:55 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 19:52:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
// unset path separately
int	option_unset(t_executor *control, t_treenode *node, t_param *param)
{
	char	*key;

	control->found = 1;
	node = node->child;
	while (node)
	{
		key = *get_node_txt(node);
		if (ft_strcmp(key, "PATH") == 0)
			ft_dlist_clear_s(&param->envvar_path_head, 0);
		else
			ft_mapss_del(param->envvars, key);
		node = node->sibling_next;
	}
	control->retval = 0;
	return (1);
}
