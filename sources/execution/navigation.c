/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:46:13 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 23:47:48 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

t_treenode	*prev_command(t_treenode *node)
{
	if (!node->sibling_prev || !node->sibling_prev->sibling_prev)
		return (0);
	if (*get_node_type(node) & CHAIN_START)
		return (0);
	node = prev_node(node);
	while (node && node->sibling_prev && (*get_node_type(node) & COMMAND) == 0)
		node = prev_node(node);
	if ((*get_node_type(node) & COMMAND) == 0)
		return (0);
	return (node);
}

t_treenode	*next_command(t_treenode *node)
{
	if (!node->sibling_next || !node->sibling_next->sibling_next)
		return (0);
	if (*get_node_type(node) & CHAIN_END)
		return (0);
	node = next_node(node);
	while (node && node->sibling_next && (*get_node_type(node) & COMMAND) == 0)
		node = next_node(node);
	if ((*get_node_type(node) & COMMAND) == 0)
		return (0);
	return (node);
}

t_treenode	*next_node(t_treenode *node)
{
	if (!node->sibling_next || !node->sibling_next->sibling_next)
		return (0);
	return (node->sibling_next->sibling_next);
}

t_treenode	*prev_node(t_treenode *node)
{
	if (!node->sibling_prev || !node->sibling_prev->sibling_prev)
		return (0);
	return (node->sibling_prev->sibling_prev);
}
