/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:40:45 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/12 20:37:13 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef struct s_treenode
{
	void		*content;
	t_treenode	*parent;
	t_treenode	*sibling_next;
	t_treenode	*sibling_prev;
	t_treenode	*child;
	int			siblings_qtty;
	int			depth;
	int			(*freecontent)(void*);
}	t_treenode;

typedef struct s_tree
{
	t_treenode	*root;
}	t_tree;

# define TREE_DEPTH_FIRST 1
# define TREE_WIDTH_FIRST 2

typedef struct s_tree_traversal_mode
{
	int	max_applications;
	int	mode;
}	t_tree_traversal_mode;
#endif
