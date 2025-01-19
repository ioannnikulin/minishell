/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:52:17 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:49:40 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	is_out_file(t_treenode *node)
{
	return (node->sibling_prev
		&& is_to_out_redir(*get_node_txt(node->sibling_prev)));
}

int	is_in_file(t_treenode *node)
{
	return (node->sibling_prev
		&& is_from_in_redir(*get_node_txt(node->sibling_prev)));
}

int	is_file(t_treenode *node)
{
	return (is_out_file(node) || is_in_file(node));
}

int	is_heredoc_eof(t_treenode *node)
{
	return (node->sibling_prev
		&& is_heredoc(*get_node_txt(node->sibling_prev)));
}
