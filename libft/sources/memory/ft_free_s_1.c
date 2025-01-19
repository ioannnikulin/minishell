/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_s_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/02 14:33:20 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_free_ss_uptonull_map(void **c, void (*f)(void **))
{
	char	**cc;
	int		i;

	if (!c)
		return ;
	cc = (char **)c;
	i = -1;
	while (cc[++ i])
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
 * node->content[2] = 0;
 * ...
 * ft_free_ss_uptonull(node->content);
 * //node->content and each element in it still contain pointers
 * to freshly freed memory
 *
 * target usage: containers (i.e. a tree with strings in nodes,
 * but since containers are generalized and content stored as void*,
 * we need a conversion here)
 * */
void	ft_free_ss_uptonull(void **c)
{
	ft_free_ss_uptonull_map(c, free_s_p);
}

/*
 * treenode *node;
 * node->content = ft_calloc_if(sizeof(char*) * 3, 1);
 * node->content[0] = ft_calloc_if(sizeof(char) * 15, 1);
 * node->content[1] = ft_calloc_if(sizeof(char) * 15, 1);
 * node->content[2] = 0;
 * ...
 * ft_free_ss_uptonull_null(&node->content);
 *
 * same as above, but also assigns nullpointers to all the pointers
 * in node->content and to node->content intself
 * */
void	ft_free_ss_uptonull_null(void ***c)
{
	if (!c)
		return ;
	ft_free_ss_uptonull_map(*c, ft_free_s_null);
	*c = 0;
}
