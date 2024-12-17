/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:40:45 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 18:36:31 by inikulin         ###   ########.fr       */
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

t_tree		*ft_tree_make(void);
t_treenode	*ft_treenode_make(void *c, t_treenode *p,
				void (*freecontent)(void **));
int			ft_tree_free(t_tree **t);
int			ft_treenode_free(t_treenode **n);
int			ft_treenode_free_rec(t_treenode **n);

int			ft_tree_print(t_tree *tree, char *(*f)(void*), char *pad);
int			ft_tree_print_s(t_tree *tree);
int			ft_tree_print_c(t_tree *tree);

int			ft_tree_apply(t_tree *tgt, int (*check)(t_treenode*),
				int (*apply)(t_treenode*), t_tree_traversal_mode mode);

int			ft_treenode_insert_child_before_first(t_treenode *parent,
				t_treenode *child, int (*cmp)(void *, void *));
int			ft_treenode_insert_child_idx(t_treenode *parent,
				t_treenode *child, int before_idx);
int			ft_treenode_insert_child_idx_s_free(t_treenode *parent, char *s,
				int before_idx);
int			ft_treenode_insert_child_idx_s_nop(t_treenode *parent, char *s,
				int before_idx);
int			ft_treenode_insert_child_idx_s_dup(t_treenode *parent, char *s,
				int before_idx);

t_treenode	*ft_treenode_cut(t_treenode *parent, int from_incl, int to_excl);

int			ft_tree_cmp(t_tree *a, t_tree *b, int (*cmp)(void *, void *));
int			ft_tree_cmp_s(t_tree *a, t_tree *b);
#endif
