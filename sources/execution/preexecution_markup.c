/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preexecution_markup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:32:33 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:08:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	chain_ends(t_treenode *node)
{
	t_treenode	*next;

	if (node->sibling_next && (!node->sibling_prev
			|| !is_pipe_or_redir(*get_node_txt(node->sibling_prev)))
		&& is_pipe_or_redir(*get_node_txt(node->sibling_next)))
		*get_node_type(node) |= CHAIN_START;
	next = node->sibling_next;
	if ((*get_node_type(node) & (FROM_PIPE | OUT_FILE | IN_FILE
				| COMMAND | HEREDOC)) != 0
		&& (!next || !is_pipe_or_redir(*get_node_txt(next))))
		*get_node_type(node) |= CHAIN_END;
	return (0);
}

int	fd_info(t_executor *e)
{
	t_treenode	*node;
	int			i;

	if (!(e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS))
		return (0);
	node = e->node;
	i = -1;
	while (node)
	{
		FT_FPRINTF(STDERR, "%i: in %i out %i type %i\n", ++i,
			*get_node_in_fd(node), *get_node_out_fd(node),
			*get_node_type(node));
		node = next_node(node);
	}
	return (0);
}

static int	rollback_pipe(t_treenode *node)
{
	if (*get_node_type(node) & (ANY_FILE | HEREDOC)
		&& *get_node_type(node) & TO_PIPE)
	{
		*get_node_type(node) &= ~TO_PIPE;
		*get_node_type(node) &= ~COMMAND;
		if (*get_node_type(node) & (IN_FILE | HEREDOC))
			add_node_type(prev_command(node), TO_PIPE);
		else if (*get_node_type(node) & OUT_FILE)
			add_node_type(next_command(node), FROM_DEV_NULL);
	}
	return (0);
}

static int	stage1(t_executor *e)
{
	t_treenode	*node;

	node = e->node;
	while (node)
	{
		add_node_type(node, ft_if_i((to_pipe(node)), TO_PIPE, 0));
		add_node_type(node, ft_if_i(from_pipe(node), FROM_PIPE, 0));
		add_node_type(node, ft_if_i(sends_to_out_file(node), TO_OUT_FILE, 0));
		add_node_type(node, ft_if_i(reads_from_in_file(node), FROM_IN_FILE, 0));
		add_node_type(node, ft_if_i(reads_from_heredoc(node), FROM_HEREDOC, 0));
		add_node_type(node, ft_if_i(*get_node_type(node), COMMAND, 0));
		add_node_type(node, ft_if_i(is_in_file(node), IN_FILE, 0));
		add_node_type(node, ft_if_i(is_out_file(node), OUT_FILE, 0));
		add_node_type(node, ft_if_i(is_heredoc_eof(node), HEREDOC, 0));
		node = next_node(node);
	}
	return (0);
}

int	markup(t_executor *e)
{
	t_treenode	*node;

	stage1(e);
	node = e->node;
	while (node)
	{
		rollback_pipe(node);
		chain_ends(node);
		node = next_node(node);
	}
	fd_info(e);
	return (0);
}
