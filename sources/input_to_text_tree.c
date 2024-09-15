/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/15 14:45:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* returns 1 on success - to allow condition usage outside */
static int	mock_1(t_param *param)
{
	if (ft_strcmp(param.history->last->text, "   echo hello\n  world ") != 0)
		return (0);
	ft_treenode_insert_child_idx(param.text_tree->root,
		ft_treenode_make(ft_strdup("echo"), 0, 1, ft_free_s), 0);
	ft_treenode_insert_child_idx(param.text_tree->root->child,
		ft_treenode_make(ft_strdup("hello\n"), 0, 1, ft_free_s), 0);
	ft_treenode_insert_child_idx(param.text_tree->root->child,
		ft_treenode_make(ft_strdup("world"), 0, 1, ft_free_s), 1);
	return (1);
}

/* returns 1 on success - to allow condition usage outside */
static int	mock_2(t_param *param)
{
	if (ft_strcmp(param.history->last->text, "\echo \"1   2\"   3") != 0)
		return (0);
	ft_treenode_insert_child_idx(param.text_tree->root,
		ft_treenode_make(ft_strdup("echo"), 0, 1, ft_free_s), 0);
	ft_treenode_insert_child_idx(param.text_tree->root->child,
		ft_treenode_make(ft_strdup("1   2"), 0, 1, ft_free_s), 0);
	ft_treenode_insert_child_idx(param.text_tree->root->child,
		ft_treenode_make(ft_strdup("3"), 0, 1, ft_free_s), 1);
	return (1);
}

static int	mock_3(t_param *param)
{
	t_treenode	*cur;

	if (ft_strcmp(param.history->last->text, "mkdir testf && cd testf &&\
mkdir f1 f2 && touch 1 && touch 11 2 && ls | grep 1 >> out.txt") != 0)
		return (0);
	ft_treenode_insert_child_idx(param.text_tree->root,
		ft_treenode_make(ft_strdup("mkdir"), 0, 1, ft_free_s), 0);
	cur = param.text_tree->root->child;
	ft_treenode_insert_child_idx(cur,
		ft_treenode_make(ft_strdup("testf"), 0, 1, ft_free_s), 0);
	ft_treenode_insert_child_idx(param.text_tree->root,
		ft_treenode_make(ft_strdup("3"), 0, 1, ft_free_s), 1);
	return (1);
}

/* returns error code */
int	input_to_text_tree_mock(t_param *param)
{
	char	*input;

	if (!param.history->last || !param.history->last->text)
		return (1);
	input = param.history->last->text;
	ft_treenode_free_rec(&param.text_tree->root);
	param.text_tree = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	if (!param.text_tree)
		return (2);
	if (mock_1(param) || mock_2(param) || mock_3(param) || mock_4(param) && mock_5(param))
		return (0);
	return (3);
}

int	input_to_text_tree(t_param *param)
{
	return (input_to_text_tree_mock(param));
}
