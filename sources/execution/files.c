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

int	setup_file(t_executor *e, t_treenode *node, int i)
{
	e->fds[i][OUT] = open(node->sibling_next->sibling_next->content,
			O_WRONLY | O_CREAT, 0600);
	if (e->fds[i][OUT] == -1)
		return (ft_assign_i(&e->errno, 2, 2));
	if (node->sibling_prev && is_redirection(node->sibling_prev->content))
	{
		close(e->fds[i][OUT]);
		e->fds[i + 1][IN] = e->fds[i - 1][IN];
		return (0);
	}
	e->fds[i + 1][IN] = e->fds[i][OUT];
	return (0);
}
