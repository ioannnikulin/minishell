/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:19:23 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/13 13:03:27 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"

typedef struct	s_node
{
	char	*content;
	char	*parent;
	char	*next;
	char	*prev;
	char	*child;
	int		child_qtty;
}	t_node;

typedef struct s_nodes
{
	t_node node[1];
} t_nodes;

typedef struct s_testcase
{
	t_nodes	nodes;
	int		nodes_qtty;
	int		exp_val;
}	t_testcase;

#define SZ 4

void check_node_content(t_treenode *node, t_node *expected) {
	assert(node != NULL && "Node should not be NULL");
	assert(strcmp((char *)node->content, expected->content) == 0);
	assert(strcmp((char *)node->parent->content, expected->parent) == 0);
	assert(node->sibling_next == NULL || strcmp((char *)node->sibling_next->content, expected->next) == 0);
	assert(node->sibling_prev == NULL || strcmp((char *)node->sibling_prev->content, expected->prev) == 0);
	assert(node->child == NULL || strcmp((char *)node->child->content, expected->child) == 0);
	assert(node->children_qtty == expected->child_qtty);
}

void	tokens_to_tree_test(void)
{
	t_nodes n;
	t_testcase t[SZ];
	
	char *token[] = {"echo", "hello", "world"};
	n.node[0] = (t_node){"echo", TEXT_TREE_ROOT, 0, 0, "hello", 1};
	n.node[1] = (t_node){"hello", "echo", "world", 0, 0, 0};
	n.node[2] = (t_node){"world", "echo", 0, "hello", 0, 0};
	t[0] = (t_testcase){n, 3, 0};
	t_tree *tree = ft_tree_make();
	assert(tree != NULL);
	t_tree *tree = tokens_to_tree(tree, token);
	assert(tree != NULL && tree->root != NULL);
	t_treenode *cur = tree->root->child;
	for (int i = 0; i < SZ && cur != NULL; i++) {
		check_node_content(cur, &t[0].nodes.node[i]);
		cur = cur->sibling_next;
	}
}