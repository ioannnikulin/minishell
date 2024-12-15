/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_controls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 11:28:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tree_make/tree_processing_internal.h"
#include <fcntl.h>

static t_control	*tofile(t_control *ctrl, char *fname, int append)
{
	ctrl->out_fd = open(fname, O_WRONLY | O_CREAT
		| ft_if_i(append, O_APPEND, 0), 0600);
	if (ctrl->out_fd == -1)
	{
		free(ctrl);
		return (0);
	}
	dup2(STDOUT, ctrl->out_fd);
	return (ctrl);
}

t_control	*make_control_set_redirs(t_treenode *node)
{
	t_control	*res;
	char		nodeptr[20];
	int			ptrstart;

	res = ft_calloc_if(sizeof(t_control), 1);
	if (!res)
		return (0);
	res->retval = 0;
	res->found = 0;
	res->in_fd = -1;
	res->out_fd = -1;
	if (!node->sibling_next)
		return (res);
	ptrstart = ft_ulltoa((t_ull)node, nodeptr);
	if (ft_strcmp(node->sibling_next->content, "|") == 0)
		return (tofile(res, &nodeptr[ptrstart], 1));
	else if (is_redirection(node->sibling_next->content))
		return (tofile(res, node->sibling_next->sibling_next->content,
				 ft_if_i(((char *)node->sibling_next->content)[1] == 0, 0, 1)));
	return (res);
}
