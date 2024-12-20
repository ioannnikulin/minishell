/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_controls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/19 23:14:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tree_make/tree_processing_internal.h"
#include <fcntl.h>

static int	to_file(t_executor *e, char *fname, int append)
{
	if (!ft_dlist_add_front_i(&e->out_fd, open(fname, O_WRONLY | O_CREAT
				| ft_if_i(append, O_APPEND, 0), 0600))
		|| *(int *)e->out_fd->content == -1)
		return (1);
	dup2(*(int *)e->out_fd->content, STDOUT_FILENO);
	return (0);
}
//maybe will have to dup not here, but in w_execve

//TODO: if in_fd exists, it's the input for us here
int	set_redirs(t_executor *e)
{
	if (!e->node->sibling_next)
		return (0);
	if (ft_strcmp(e->node->sibling_next->content, "|") == 0)
		return (to_pipe(e));
	else if (is_redirection(e->node->sibling_next->content))
		return (to_file(e, e->node->sibling_next->sibling_next->content,
				ft_if_i(((char *)e->node->sibling_next->content)[1]
				== 0, 0, 1)));
	return (0);
}

//TODO: 
int	unset_redirs(t_executor *e)
{
	(void)e;
	return (0);
}

t_executor	*make_executor(t_treenode *node, t_param *param)
{
	t_executor	*res;

	res = ft_calloc_if(sizeof(t_executor), 1);
	if (!res)
		return (0);
	res->retval = 0;
	res->found = 0;
	res->in_fd = 0;
	res->out_fd = 0;
	res->node = node;
	res->param = param;
	return (res);
}
