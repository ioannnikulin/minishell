/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:46:13 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:30:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

t_treenode	*next_in_file(t_treenode *node)
{
	if (!node->sibling_next || !node->sibling_next->sibling_next)
		return (0);
	if (*get_node_type(node) & CHAIN_END)
		return (0);
	node = next_node(node);
	while (node && node->sibling_next && (*get_node_type(node) & IN_FILE) == 0)
		node = next_node(node);
	if ((*get_node_type(node) & IN_FILE) == 0)
		return (0);
	return (node);
}