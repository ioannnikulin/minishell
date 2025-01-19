/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_node_interacting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:52:17 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 11:32:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	reads_from_in_file(t_treenode *node)
{
	return (node->sibling_next
		&& is_from_in_redir(*get_node_txt(node->sibling_next)));
}

int	sends_to_out_file(t_treenode *node)
{
	return (node->sibling_next
		&& is_to_out_redir(*get_node_txt(node->sibling_next)));
}

int	takes_part_in_file(t_treenode *node)
{
	return (sends_to_out_file(node) || is_out_file(node)
		|| reads_from_in_file(node) || is_in_file(node));
}

int	reads_from_heredoc(t_treenode *node)
{
	return (node->sibling_next
		&& is_heredoc(*get_node_txt(node->sibling_next)));
}

int	takes_part_in_pipe_or_file(t_treenode *node)
{
	return (takes_part_in_file(node) || takes_part_in_pipe(node)
		|| reads_from_heredoc(node) || is_heredoc_eof(node));
}
