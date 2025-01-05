/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/02 14:33:30 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * treenode *node;
 * node->content = ft_calloc_if(sizeof(char) * 15, 1);
 * ...
 * ft_free_s(node->content);
 * //node->content still contains pointer to freshly freed memory
 *
 * target usage: containers (i.e. a tree with strings in nodes,
 * but since containers are generalized and content stored as void*,
 * we need a conversion here)
 * */
void	ft_free_s(void *c)
{
	char	*cc;

	cc = c;
	free(cc);
}

static void	ft_free_ss_sz_map(void **c, int sz, void (*f)(void **))
{
	char	**cc;
	int		i;

	if (!c)
		return ;
	cc = (char **)c;
	i = -1;
	while (++i < sz)
		f((void **)&cc[i]);
	free(cc);
}

static void	free_s_p(void **c)
{
	char	*cc;

	if (!c)
		return ;
	cc = *c;
	free(cc);
}

/*
 * treenode *node;
 * node->content = ft_calloc_if(sizeof(char*) * 3, 1);
 * node->content[0] = ft_calloc_if(sizeof(char) * 15, 1);
 * node->content[1] = ft_calloc_if(sizeof(char) * 15, 1);
 * node->content[2] = ft_calloc_if(sizeof(char) * 15, 1);
 * ...
 * ft_free_ss_sz(node->content, 3);
 * // node->content and each element in it still contain pointers
 * // to freshly freed memory
 *
 * target usage: containers (i.e. a tree with strings in nodes,
 * but since containers are generalized and content stored as void*,
 * we need a conversion here)
 * */
void	ft_free_ss_sz(void **c, int sz)
{
	ft_free_ss_sz_map(c, sz, free_s_p);
}

/*
 * treenode *node;
 * node->content = ft_calloc_if(sizeof(char*) * 3, 1);
 * node->content[0] = ft_calloc_if(sizeof(char) * 15, 1);
 * node->content[1] = ft_calloc_if(sizeof(char) * 15, 1);
 * node->content[2] = ft_calloc_if(sizeof(char) * 15, 1);
 * ...
 * ft_free_ss_sz_null(&node->content, 3);
 *
 * same as above, but also assigns nullpointers to all the pointers
 * in node->content and to node->content intself
 * */
void	ft_free_ss_sz_null(void ***c, int sz)
{
	if (!c)
		return ;
	ft_free_ss_sz_map(*c, sz, ft_free_s_null);
	*c = 0;
}
