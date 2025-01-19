/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treenode_ops_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:10:25 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:50:21 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_txt(void *content)
{
	t_command	*cmd;

	cmd = content;
	return (cmd->txt);
}

int	cmd_cmp(void *a, void *b)
{
	return (ft_strcmp(cmd_txt(a), cmd_txt(b)));
}

int	add_node_type(t_treenode *node, int type)
{
	*get_node_type(node) |= type;
	return (*get_node_type(node));
}
