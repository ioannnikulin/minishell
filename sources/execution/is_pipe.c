/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:52:39 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 16:58:41 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	is_pipe(char *c)
{
	return (ft_strcmp(c, "|") == 0);
}

int	is_pipe_or_redir(char *c)
{
	return (is_pipe(c) || is_redirection(c));
}

int	from_pipe(t_treenode *node)
{
	return (node->sibling_prev && is_pipe(*get_node_txt(node->sibling_prev)));
}

int	to_pipe(t_treenode *node)
{
	return (node->sibling_next
		&& is_pipe(*get_node_txt(node->sibling_next)));
}

int	takes_part_in_pipe(t_treenode *node)
{
	return (to_pipe(node) || from_pipe(node));
}
