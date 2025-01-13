/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@stiudent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/12 12:25:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	mode(char *s)
{
	if (s[0] == '>')
	{
		if (s[1] == '>')
			return (O_WRONLY | O_CREAT | O_APPEND);
		return (O_WRONLY | O_CREAT | O_TRUNC);
	}
	if (s[0] == '<')
		return (O_RDONLY);
	return (0);
}

int	setup_file(t_executor *e, t_treenode *node, int i)
{
	e->fds[i][OUT] = open(node->sibling_next->sibling_next->content,
			mode(node->sibling_next->content), 0600);
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
