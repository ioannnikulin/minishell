/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_controls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/12 14:37:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tree_make/tree_processing_internal.h"

int	scroll_chain(t_executor *e, int tgt)
{
	while (tgt-- > 0)
		e->node = e->node->sibling_next->sibling_next;
	return (0);
}

int	fd_ok(int fd)
{
	return (fcntl(fd, F_GETFD) != -1);
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
