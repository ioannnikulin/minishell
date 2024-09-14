/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:40:45 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 21:48:36 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H
# include "../../libft.h"

typedef struct s_treenode
{
	void				*content;
	struct s_treenode	*parent;
	struct s_treenode	*sibling_next;
	struct s_treenode	*sibling_prev;
	struct s_treenode	*child;
	int					children_qtty;
	int					depth;
	void				(*freecontent)(void**);
}	t_treenode;

typedef struct s_tree
{
	t_treenode	*root;
	int			nodes_qtty;
}	t_tree;

# define TREE_DEPTH_FIRST 1
# define TREE_WIDTH_FIRST 2

typedef struct s_tree_traversal_mode
{
	int	max_applications;
	int	mode;
}	t_tree_traversal_mode;

t_tree	*ft_tree_make();
t_treenode	*ft_treenode_make(void *c, t_treenode *p, int d, void (*freecontent)(void **));
int	ft_treenode_free(t_treenode **n);
int	ft_treenode_free_rec(t_treenode **n);

int	ft_tree_print(t_tree *tree, char *(*f)(void*), char *pad);
int	ft_tree_print_s(t_tree *tree);
int	ft_tree_print_c(t_tree *tree);

int	ft_tree_apply(t_tree *tgt, int (*check)(t_treenode*), int (*apply)(t_treenode*),
				t_tree_traversal_mode mode);
int	ft_treenode_insert_child_before_first(t_treenode *parent, t_treenode *child, int (*cmp)(void *, void *));
int	ft_treenode_insert_child_idx(t_treenode *parent, t_treenode *child, int before_idx);
#endif
