/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_controls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/12 13:57:18 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tree_make/tree_processing_internal.h"

int	is_pipe(char *c)
{
	return (ft_strncmp(c, "|", 2) == 0);
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

int	executor_finalize(t_executor *e)
{
	int	i;

	i = -1;
	if (e->fds)
	{
		while (++i < e->chain_length + 1)
			free(e->fds[i]);
	}
	free(e->fds);
	free(e->pids);
	free(e);
	return (0);
}
