/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/19 23:23:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static void	close_free(void *p)
{
	int	*pi;

	pi = p;
	close(*pi);
	free(pi);
}

int	from_pipe(t_executor *e)
{
	t_dlist	*todel;

	dup2(*(int *)e->in_fd->content, STDIN_FILENO);
	if (exec_rec(e) != 0)
		return (1);
	todel = e->in_fd;
	e->in_fd = e->in_fd->next;
	ft_dlist_delone(todel, close_free);
	todel = e->out_fd;
	e->out_fd = e->out_fd->next;
	ft_dlist_delone(todel, close_free);
	return (0);
}

int	to_pipe(t_executor *e)
{
	int	p[2];

	if (pipe(p) < 0)
		return (ft_assign_i(&e->param->opts.errno, 1, 1));
	if (!ft_dlist_add_front_i(&e->out_fd, p[1]))
		return (ft_assign_i(&e->param->opts.errno, 2, 2));
	if (!ft_dlist_add_front_i(&e->in_fd, p[0]))
		return (ft_assign_i(&e->param->opts.errno, 3, 3));
	dup2(*(int *)e->out_fd->content, STDOUT_FILENO);
	return (0);
}
