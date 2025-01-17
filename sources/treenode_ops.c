/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treenode_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:19:45 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/16 16:20:31 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_node_type(t_treenode *node)
{
	return (&((t_command *)(node->content))->type);
}

int	*get_node_in_fd(t_treenode *node)
{
	return (&((t_command *)(node->content))->in_fd);
}

int	*get_node_out_fd(t_treenode *node)
{
	return (&((t_command *)(node->content))->out_fd);
}

char	**get_node_txt(t_treenode *node)
{
	return (&((t_command *)(node->content))->txt);
}

pid_t	*get_node_pid(t_treenode *node)
{
	return (&((t_command *)(node->content))->pid);
}