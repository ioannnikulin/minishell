/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 21:47:53 by inikulin         ###   ########.fr       */
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

static int	ignored_file(t_executor *e, t_treenode *node, int fd)
{
	if (close(fd) == -1)
		return (ft_assign_i(&e->errno, 3, 3));
	fd = *get_node_out_fd(prev_node(node));
	*get_node_in_fd(node) = fd;
	*get_node_out_fd(node) = fd;
	*get_node_in_fd(next_node(node)) = fd;
	*get_node_out_fd(next_node(node)) = fd;
	*get_node_type(node) |= IGNORED_FILE;
	return (0);
}

int	setup_out_file(t_executor *e, t_treenode *node)
{
	int	fd;

	if ((*get_node_type(node) & TO_OUT_FILE) == 0)
		return (0);
	fd = open(*get_node_txt(next_node(node)),
			mode(*get_node_txt(node->sibling_next)), 0600);
	if (fd == -1)
		return (ft_assign_i(&e->errno, 2, 2));
	*get_node_out_fd(node) = fd;
	if (*get_node_type(node) & OUT_FILE)
		return (ignored_file(e, node, fd));
	*get_node_in_fd(next_node(node)) = fd;
	*get_node_out_fd(next_node(node)) = fd;
	return (0);
}

// fd is written only to the file node for now. to command node - in rollback
int	setup_in_file(t_executor *e, t_treenode *node)
{
	int	fd;

	if ((*get_node_type(node) & IN_FILE) == 0)
		return (0);
	fd = open(*get_node_txt(node),
			mode(*get_node_txt(node->sibling_prev)), 0600);
	if (fd == -1)
	{
		FT_FPRINTF(STDERR, "%s: %s: %s\n", TXT_MINISHELL,
			*get_node_txt(node), ERR_NO_IN_FILE);
		return (ft_assign_i(&e->errno, NO_IN_FILE, NO_IN_FILE));
	}
	*get_node_out_fd(node) = fd;
	*get_node_in_fd(node) = fd;
	return (0);
}

// works only for last file of input file sequence,
// e.g. ls < file1 < _file2_ > file3
// also ls < _file1_ > file3
int	rollback_input_files_fds(t_executor *e, t_treenode *node)
{
	int	fd;

	if (!(*get_node_type(node) & IN_FILE)
		|| (node->sibling_next && (*get_node_type(next_node(node)) & IN_FILE)))
		return (0);
	fd = *get_node_out_fd(node);
	node = prev_node(node);
	while (node && (*get_node_type(node) & IN_FILE))
	{
		if (close(*get_node_out_fd(node)) == -1)
			return (ft_assign_i(&e->errno, 3, 3));
		*get_node_out_fd(node) = fd;
		*get_node_in_fd(node) = fd;
		*get_node_type(node) |= IGNORED_FILE;
		node = prev_node(node);
	}
	if (!node)
		return (ft_assign_i(&e->errno, 4, 4));
	if (close(*get_node_in_fd(node)) == -1)
		return (ft_assign_i(&e->errno, 4, 4));
	*get_node_in_fd(node) = fd;
	return (0);
}