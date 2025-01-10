/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 18:19:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	mode(t_treenode *node)
{
	if (node->sibling_next && ft_strcmp(node->sibling_next->content, ">>") == 0)
		return (O_APPEND);
	return (O_TRUNC);
}

int	setup_file(t_executor *e, t_treenode *node, int i)
{
	if (!node->sibling_next || !node->sibling_next->sibling_next)
	{
		e->fds[i][TYPE] |= LAST_FILE;
		return(0);
	}
	e->fds[i][OUT] = open(node->sibling_next->sibling_next->content,
			O_WRONLY | O_CREAT | mode(node), 0600);
	if (e->fds[i][OUT] == -1)
		return (ft_assign_i(&e->errno, 2, 2));
	if (i > 0 && node->sibling_prev)
	{
		if (is_redirection(node->sibling_prev->content))
		{
			e->fds[i][TYPE] |= DUMMY_FILE;
			close(e->fds[i][OUT]);
			e->fds[i + 1][IN] = e->fds[i - 1][IN];
			return (0);
		}
		e->fds[i - 1][TYPE] |= TO_FILE;
	}
	e->fds[i][TYPE] |= TO_FILE;
	e->fds[i + 1][IN] = e->fds[i][OUT];
	return (0);
}
