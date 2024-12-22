/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_controls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 18:17:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tree_make/tree_processing_internal.h"

int	is_pipe(char *c)
{
	return (ft_strcmp(c, "|") == 0);
}

int	is_pipe_or_redir(char *c)
{
	return (is_pipe(c) || is_redirection(c));
}

int	takes_part_in_pipe(t_treenode *node)
{
	int	res;

	res = ((node->sibling_next && is_pipe(node->sibling_next->content))
			|| (node->sibling_prev && is_pipe(node->sibling_prev->content)));
	return (res);
}

t_executor	*make_executor(t_treenode *node, t_param *param)
{
	t_executor	*res;

	res = ft_calloc_if(sizeof(t_executor), 1);
	if (!res)
		return (0);
	res->retval = 0;
	res->found = 0;
	res->node = node;
	res->param = param;
	return (res);
}
