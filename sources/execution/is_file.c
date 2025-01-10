/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:33:24 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	is_file(char *c)
{
	return (ft_strcmp(c, ">") == 0 || ft_strcmp(c, ">>") == 0);
}

int from_file(t_treenode *node)
{
	return (node->sibling_prev && is_file(node->sibling_prev->content));
}

int to_file(t_treenode *node)
{
	return (node->sibling_next && is_file(node->sibling_next->content));
}

int	takes_part_in_file(t_treenode *node)
{
	return (to_file(node) || from_file(node));
}