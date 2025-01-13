/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 22:04:28 by inikulin         ###   ########.fr       */
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

int	setup_out_file(t_executor *e, t_treenode *node, int i)
{
	e->fds[i][OUT] = open(node->sibling_next->sibling_next->content,
			mode(node->sibling_next->content), 0600);
	if (e->fds[i][OUT] == -1)
		return (ft_assign_i(&e->errno, 2, 2));
	if (node->sibling_prev && is_redirection(node->sibling_prev->content))
	{
		close(e->fds[i][OUT]);
		e->fds[i + 1][IN] = e->fds[i - 1][IN];
		e->fds[i][TYPE] |= TO_OUT_FILE | IGNORED_FILE;
		return (0);
	}
	e->fds[i + 1][IN] = e->fds[i][OUT];
	e->fds[i][TYPE] |= TO_OUT_FILE;
	return (0);
}

int	setup_in_file(t_executor *e, t_treenode *node, int i)
{
	e->fds[i + 1][OUT] = open(node->sibling_next->sibling_next->content,
			mode(node->sibling_next->content), 0600);
	if (e->fds[i + 1][OUT] == -1)
	{
		FT_FPRINTF(STDERR, "%s: %s: %s\n", TXT_MINISHELL,
			node->sibling_next->sibling_next->content, ERR_NO_IN_FILE);
		return (ft_assign_i(&e->errno, NO_IN_FILE, NO_IN_FILE));
	}
	return (0);
}

int	rollback_input_files_fds(t_executor *e, t_treenode *node, int i)
{
	int	fd;

	if (!is_in_file(node) || (node->sibling_next
			&& is_in_file(node->sibling_next->sibling_next)))
		return (0);
	fd = e->fds[i][OUT];
	while (node->sibling_prev && is_in_file(node->sibling_prev->sibling_prev))
	{
		i --;
		if (close(e->fds[i][OUT]) == -1)
			return (ft_assign_i(&e->errno, 3, 3));
		e->fds[i][OUT] = fd;
		e->fds[i][IN] = fd;
		e->fds[i][TYPE] |= FROM_IN_FILE | IGNORED_FILE;
		node = node->sibling_prev->sibling_prev;
	}
	i --;
	if (close(e->fds[i][IN]) == -1)
		return (ft_assign_i(&e->errno, 4, 4));
	e->fds[i][IN] = fd;
	e->fds[i][TYPE] |= FROM_IN_FILE;
	return (0);
}