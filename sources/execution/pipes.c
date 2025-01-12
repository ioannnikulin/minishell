/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/12 13:57:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	close_pipes(t_executor *e)
{
	int	i;

	i = -1;
	while (++i < e->chain_length)
	{
		if (e->fds[i][IN] != STDIN_FILENO && close(e->fds[i][IN]))
		{
			perror("close failed");
			return (ft_assign_i(&e->errno, 1, 1));
		}
		if (e->fds[i][OUT] != STDOUT_FILENO && close(e->fds[i][OUT]))
		{
			perror("close failed");
			return (ft_assign_i(&e->errno, 1, 1));
		}
	}
	return (0);
}

int	setup_pipe(t_executor *e, int i)
{
	int	p[2];

	if (pipe(p) < 0)
		return (ft_assign_i(&e->errno, 2, 2));
	e->fds[i][OUT] = p[OUT];
	e->fds[i + 1][IN] = p[IN];
	return (0);
}
