/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 18:21:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

// ANY_FILE suspicious
int	close_pipes(t_executor *e, int source)
{
	int	i;

	i = -1;
	while (++i < e->chain_length)
	{
		if (e->fds[i][IN] != STDIN_FILENO && fcntl(e->fds[i][IN], F_GETFD) != -1)
		{
			FT_FPRINTF(STDERR, "%i in closing %i, type %i\n", source, e->fds[i][IN], e->fds[i][TYPE]);
			if (close(e->fds[i][IN]))
			{
				FT_FPRINTF(STDERR, "%i in close failed %i\n", source, e->fds[i][IN]);
				return (ft_assign_i(&e->errno, 1, 1));
			}
			e->fds[i][IN] = STDIN_FILENO;
		}
		if (e->fds[i][OUT] != STDOUT_FILENO && fcntl(e->fds[i][OUT], F_GETFD) != -1)
		{
			FT_FPRINTF(STDERR, "%i out closing %i, type %i\n", source, e->fds[i][OUT], e->fds[i][TYPE]);
			if (close(e->fds[i][OUT]))
			{
				FT_FPRINTF(STDERR, "%i out close failed %i\n", source, e->fds[i][OUT]);
				return (ft_assign_i(&e->errno, 2, 2));
			}
			e->fds[i][OUT] = STDOUT_FILENO;
		}
	}
	return (0);
}

int	setup_pipe(t_executor *e, t_treenode *node, int i)
{
	int	p[2];

	if (to_pipe(node))
	{
		if (pipe(p) < 0)
			return (ft_assign_i(&e->errno, 2, 2));
		e->fds[i][OUT] = p[OUT];
		e->fds[i + 1][IN] = p[IN];
	}
	if (!from_pipe(node))
		e->fds[i][TYPE] |= FIRST_IN_PIPE;
	if (!to_pipe(node))
		e->fds[i][TYPE] |= LAST_IN_PIPE;
	if (e->fds[i][TYPE] == 0)
		e->fds[i][TYPE] |= PIPE;
	return (0);
}
