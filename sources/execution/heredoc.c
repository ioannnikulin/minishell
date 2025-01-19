/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:06:24 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/19 15:11:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"
#include <termios.h>

static int	resend(char *delim, int fd)
{
	char	*line;

	while (1)
	{
		rl_outstream = stderr;
		line = readline("> ");
		rl_outstream = stdout;
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
	int	fd[2];
	int	devnull;

	if (!(*get_node_type(node) & HEREDOC))
		return (0);
	if (pipe(fd) == -1)
		return (ft_assign_i(&e->errno, 1, 1));
	*get_node_out_fd(node) = fd[OUT];
	resend(*get_node_txt(node), fd[OUT]);
	if (close(*get_node_out_fd(node)))
		return (ft_assign_i(&e->errno, 1, 1));
	if (is_last_heredoc(node))
		*get_node_in_fd(prev_command(node)) = fd[IN];
	else
	{
		devnull = open("/dev/null", O_WRONLY);
		if (devnull == -1)
			return (ft_assign_i(&e->errno, 2, 2));
		if (dup2(devnull, fd[IN]) == -1)
			return (ft_assign_i(&e->errno, 3, 3));
		if (close(devnull) == -1 || close(fd[IN]) == -1)
			return (ft_assign_i(&e->errno, 4, 4));
	}
	return (0);
}

int	child_heredoc(t_executor *e, t_treenode *node)
{
	if (close(*get_node_out_fd(node)) == -1)
		return (ft_assign_i(&e->errno, 1, 1));
	return (0);
}
