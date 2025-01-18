/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:06:24 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:03:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	resend(char *delim, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, delim))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	return (0);
}

int	setup_heredoc(t_executor *e, t_treenode *node)
{
	int		fd[2];

	if (!(*get_node_type(node) & HEREDOC))
		return (0);
	if (pipe(fd) == -1)
		return (ft_assign_i(&e->errno, 1, 1));
	*get_node_out_fd(node) = fd[OUT];
	*get_node_in_fd(prev_command(node)) = fd[IN];
	resend(*get_node_txt(node), fd[OUT]);
	if (close(*get_node_out_fd(node)))
		return (ft_assign_i(&e->errno, 1, 1));
	return (0);
}

int	child_heredoc(t_executor *e, t_treenode *node)
{

	if (close(*get_node_out_fd(node)) == -1)
		return (ft_assign_i(&e->errno, 1, 1));
	return (0);
}