/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:52:17 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 17:00:00 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	is_to_out_redir(char *c)
{
	return (ft_strcmp(c, ">") == 0 || ft_strcmp(c, ">>") == 0);
}

int	is_from_in_redir(char *c)
{
	return (ft_strcmp(c, "<") == 0);
}

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
