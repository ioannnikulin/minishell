/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:19:23 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/16 19:29:27 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define DEBUG

typedef struct	s_node
{
	char	*parent;
	void	*content;
	char	*next;
	char	*prev;
	char	*child;
	int		child_qtty;
}	t_node;

typedef struct s_nodes
{
	t_node node[4];
} t_nodes;

typedef struct s_testcase
{
	t_nodes	n;
	int		nodes_qtty;
	int		exp_val;
}	t_testcase;

#define SZ 4

static void check_tree_content(t_treenode *node, t_node *expected_nodes, int *current_index, int total_nodes)
{
	if (node == NULL || *current_index >= total_nodes)
		return;
	t_node *expected = &expected_nodes[*current_index];
	assert(ft_strcmp((char *)node->content, (char *)expected->content) == 0);
	assert(node->children_qtty == expected->child_qtty);
	#ifdef DEBUG
	ft_printf("Checking node %d: %s, Children_qtty: %i\n", *current_index, (char *)node->content);
	ft_printf("Expected: %s, Parent: %s\n", expected->content, expected->parent);
	#endif
	(*current_index)++;
	if (node->child != NULL)
	{
		check_tree_content(node->child, expected_nodes, current_index, total_nodes);
	}
	if (node->sibling_next != NULL)
		check_tree_content(node->sibling_next, expected_nodes, current_index, total_nodes);
}

void	tokens_to_tree_test(void)
{
	int			current_index = 0;
	t_nodes n;
	t_testcase t[SZ];
	
	char *token[] = {"echo", "hello", "world", NULL};
	n.node[0] = (t_node){TEXT_TREE_ROOT, TEXT_TREE_ROOT, 0, 0, "echo", 1};
	n.node[1] = (t_node){TEXT_TREE_ROOT, "echo", 0, 0, "hello", 1};
	n.node[2] = (t_node){"echo", "hello", "world", 0, 0, 0};
	n.node[3] = (t_node){"echo", "world", 0, "hello", 0, 0};
	t[0] = (t_testcase){n, 4, 0};
	t_tree *tree = ft_tree_make();
	assert(tree != NULL);
	tokens_to_tree(tree, token);
	assert(tree != NULL && tree->root != NULL);
	ft_printf("Ch root: %i\n Ch echo: %i\n, Ch hello: %i\n, Ch world: %i\n", tree->root, tree->root->child, tree->root->child->child, tree->root->child->child->sibling_next);
	check_tree_content(tree->root, t[0].n.node, &current_index, t[0].nodes_qtty);
	assert(current_index == t[0].nodes_qtty);
}