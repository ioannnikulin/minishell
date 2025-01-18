/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:06:24 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 16:13:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	setup_heredoc(t_executor *e, t_treenode *node)
{
	int		fd[2];

	if (!(*get_node_type(node) & HEREDOC))
		return (0);
	if (pipe(fd) == -1)
		return (ft_assign_i(&e->errno, 1, 1));
	*get_node_out_fd(node) = fd[OUT];
	*get_node_in_fd(prev_command(node)) = fd[IN];
	return (0);
}

int	child_heredoc(t_executor *e, t_treenode *node)
{
	char	*line;
	char	*delim;

	delim = *get_node_txt(next_node(node));
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(delim, line))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, *get_node_out_fd(node));
		ft_putstr_fd("\n", *get_node_out_fd(node));
		free(line);
	}
	if (close(*get_node_out_fd(node)) == -1)
		return (ft_assign_i(&e->errno, 1, 1));
	return (0);
}