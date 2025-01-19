/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_file_rollback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/19 17:28:23 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

// works only for last file of output file sequence,
// e.g. ls > file1 > _file2_ > file3
// also ls > _file1_ > file3
int	rollback_output_files_fds(t_executor *e, t_treenode *node)
{
	int	fd;

	if (!(*get_node_type(node) & OUT_FILE)
		|| (node->sibling_next && (*get_node_type(next_node(node)) & OUT_FILE)))
		return (0);
	fd = *get_node_in_fd(node);
	node = prev_node(node);
	while (node && (*get_node_type(node) & OUT_FILE))
	{
		if (*get_node_in_fd(node) != STDIN
			&& close(*get_node_in_fd(node)) == -1)
			return (ft_assign_i(&e->errno, 3, 3));
		*get_node_in_fd(node) = fd;
		*get_node_out_fd(node) = fd;
		*get_node_type(node) |= IGNORED_FILE;
		node = prev_node(node);
	}
	if (!node)
		return (ft_assign_i(&e->errno, 4, 4));
	if (*get_node_out_fd(node) != STDOUT && close(*get_node_out_fd(node)) == -1)
		return (ft_assign_i(&e->errno, 5, 5));
	*get_node_out_fd(node) = fd;
	return (0);
}
