/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/12 19:35:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

t_tree	*ft_tree_make()
{
	t_tree	*res;

	res = ft_calloc_if(sizeof(t_tree), 1);
	return (res);
}

int	ft_treenode_insert_child_idx(t_treenode *parent, t_treenode *child, int before_idx)
{
	int			i;
	t_treenode	*cur;

	i = -1;
	cur = parent->child;
	if (!cur)
	{
		parent->child = child;
		child->parent = parent;
		return (0);
	}
	while (++ i < before_idx && cur->sibling_next)
		cur = cur->sibling_next;
	if (cur->sibling_next)
		cur->sibling_next->sibling_prev = child;
	child->sibling_next = cur->sibling_next;
	child->sibling_prev = cur;
	cur->sibling_next = child;
	child->parent = parent;
	return (i);
}

int	ft_treenode_insert_child_before_first(t_treenode *parent, t_treenode *child, int (*cmp)(void *, void *))
{
	int			i;
	t_treenode	*cur;

	i = -1;
	cur = parent->child;
	if (!cur)
	{
		parent->child = child;
		child->parent = parent;
		return (0);
	}
	while (!cmp(child->content, cur->content) && cur->sibling_next)
	{
		cur = cur->sibling_next;
		i ++;
	}
	if (cur->sibling_next)
		cur->sibling_next->sibling_prev = child;
	child->sibling_next = cur->sibling_next;
	child->sibling_prev = cur;
	cur->sibling_next = child;
	child->parent = parent;
	return (i);
}

t_treenode	*ft_treenode_make(void *c, t_treenode *p, int d, int (*freecontent)(void *))
{
	t_treenode *res;

	res = ft_calloc_if(t_treenode);
	if (!res)
		return (0);
	res->content = c;
	res->parent = p;
	res->depth = d;
	res->sibling_next = 0;
	res->sibling_prev = 0;
	res->child = 0;
	res->siblings_qtty = 0;
	return (res);
}

int	ft_treenode_free(t_treenode **n)
{
	if (!*n)
		return (1);
	(*n)->parent = 0;
	(*n)->sibling_next = 0;
	(*n)->sibling_prev = 0;
	(*n)->child = 0;
	(*n)->freecontent((*n)->content);
	(*n)->content = 0;
	free(**n);
	*n = 0;
	return (0);
}

int	ft_treenode_free_rec(t_treenode **n)
{
	if (!*n)
		return (1);
	if ((*n)->sibling_next)
		ft_treenode_rec(&(*n)->sibling_next);
	if ((*n)->child)
		ft_treenode_rec(&(*n)->child);
	ft_treenode_free(n);
	return (0);
}

int	ft_free_s(void **c, int ret)
{
	char	*cc;

	cc = *c;
	free(cc);
	*c = 0;
	return (ret);
}

int	ft_free_nop(void *c, int ret)
{
	(void)c;
	return (ret);
}

void	*ft_new_pi_pvoid(int i)
{
	return (ft_new_pi(i));
}

int	*ft_new_pi(int i)
{
	int	*res;

	res = ft_calloc_if(sizeof(int), 1);
	if (!res)
		return (0);
	*res = i;
	return (res);
}

int	ft_free_pi(void **p, int ret)
{
	int	*pp;

	pp = *p;
	free(pp);
	*p = 0;
	return (ret);
}

int	ft_cmp_pvoid_pi(void *a, void *b)
{
	int	aa;
	int	bb;

	aa = *(int*)a;
	bb = *(int*)b;
	return (aa - bb);
}

int	ft_less_eq_pvoid_pi(void *a, void *b)
{
	return (ft_cmp_pvoid_pi(a, b) <= 0);
}
