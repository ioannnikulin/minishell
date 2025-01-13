/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@stiudent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/12 12:08:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	close_fds(t_executor *e, int tgt)
{
	int	i;

	i = -1;
	while (++i < e->chain_length)
	{
		if (e->fds[i][IN] != STDIN && fcntl(e->fds[i][IN], F_GETFD) != -1)
		{
			if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
				FT_FPRINTF(STDERR, "%i: closing in %i\n", tgt, e->fds[i][IN]);
			if (close(e->fds[i][IN]) && FT_FPRINTF(STDERR, "%i: :( in", tgt))
				return (ft_assign_i(&e->errno, 1, 1));
			e->fds[i][IN] = STDIN;
		}
		if (e->fds[i][OUT] != STDOUT && fcntl(e->fds[i][OUT], F_GETFD) != -1)
		{
			if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
				FT_FPRINTF(STDERR, "%i: closing out %i\n", tgt, e->fds[i][OUT]);
			if (close(e->fds[i][OUT]) && FT_FPRINTF(STDERR, "%i: :( out", tgt))
				return (ft_assign_i(&e->errno, 1, 1));
			e->fds[i][OUT] = STDOUT;
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
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
		FT_FPRINTF(STDERR, "made pipe %i>%i for %i\n",
			e->fds[i + 1][IN], e->fds[i][OUT], i);
	return (0);
}
