/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 16:25:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	body(t_executor *e, t_treenode *node, int msg_src)
{
	int	fd;

	fd = *get_node_in_fd(node);
	if (fd != STDIN && fcntl(fd, F_GETFD) != -1)
	{
		if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
			FT_FPRINTF(STDERR, "%i: closing in %i\n", msg_src, fd);
		if (close(fd) && FT_FPRINTF(STDERR, "%i: :( in", msg_src))
			return (ft_assign_i(&e->errno, 1, 1));
		*get_node_in_fd(node) = STDIN;
	}
	fd = *get_node_out_fd(node);
	if (fd != STDOUT && fcntl(fd, F_GETFD) != -1)
	{
		if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
			FT_FPRINTF(STDERR, "%i: closing out %i\n", msg_src, fd);
		if (close(fd) && FT_FPRINTF(STDERR, "%i: :( out", msg_src))
			return (ft_assign_i(&e->errno, 1, 1));
		*get_node_out_fd(node) = STDOUT;
	}
	return (0);
}

int	close_fds(t_executor *e, int msg_src)
{
	t_treenode	*node;

	node = e->node;
	while ((*get_node_type(node) & CHAIN_START) == 0)
		node = prev_node(node);
	while (1)
	{
		if (body(e, node, msg_src))
			return (1);
		if ((*get_node_type(node) & CHAIN_END))
			break ;
		node = next_node(node);
	}
	return (0);
}

int	setup_dev_null(t_executor *e, t_treenode *node)
{
	int	fd;

	if ((*get_node_type(node) & FROM_DEV_NULL) == 0)
		return (0);
	fd = open("/dev/null", O_RDONLY);
	if (*get_node_in_fd(node) == -1)
		return (ft_assign_i(&e->errno, 1, 1));
	*get_node_in_fd(node) = fd;
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
		FT_FPRINTF(STDERR, "/dev/null input %i for %i\n",
			*get_node_in_fd(node), 0);
	return (0);
}

int	setup_pipe(t_executor *e, t_treenode *node, int i)
{
	int	p[2];

	if ((*get_node_type(node) & TO_PIPE) == 0)
		return (0);
	if (pipe(p) < 0)
		return (ft_assign_i(&e->errno, 2, 2));
	*get_node_out_fd(node) = p[OUT];
	node = next_command(node);
	if (!node)
		return (ft_assign_i(&e->errno, 3, 3));
	*get_node_in_fd(node) = p[IN];
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
		FT_FPRINTF(STDERR, "made pipe %i>%i for %i\n", p[IN], p[OUT], i);
	return (0);
}
