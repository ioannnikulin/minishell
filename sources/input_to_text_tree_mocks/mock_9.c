/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/21 02:49:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_9_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "export", 0);
	ft_treenode_insert_child_idx_s_dup(cur->child, "foo=bar", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "export", 2);
	cur = cur->child->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "foo=zah", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "nope=uhoh", 1);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "unset", 4);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "nope", 0);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 5);
	ft_treenode_insert_child_idx_s_dup(cur->parent,
		"./tests/tool_print_environment", 6);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "one", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "two   three", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "four", 2);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_9(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_9_TEXT) != 0)
		return (0);
	mock_9_tree(root);
	return (1);
}
