/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 13:48:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"
#include "../tree_make/tree_processing_internal.h"

static int	wclose(int fd, int i, int tgt)
{
	ft_fprintf(2, "child %i iteration %i closing %i\n", tgt, i, fd);
	return (close(fd));
}

static int	wdup2(int to, int who, int i, int tgt)
{
	ft_fprintf(2, "child %i iteration %i setting %i to %i\n", tgt, i, who, to);
	return (dup2(to, who));
}

// maybe for files openness of fds should be different?..
static int	child(t_executor *e, int tgt)
{
	int		i;

	i = -1;
	if (e->fds[tgt][IN] != STDIN_FILENO)
	{
		wdup2(e->fds[tgt][IN], STDIN_FILENO, tgt, tgt);//TODO: check errors
		wclose(e->fds[tgt][IN], tgt, tgt);
	}
	if (e->fds[tgt][OUT] != STDOUT_FILENO)
	{
		wdup2(e->fds[tgt][OUT], STDOUT_FILENO, tgt, tgt);
		wclose(e->fds[tgt][OUT], tgt, tgt);
	}
	while (++i < e->chain_length)
	{
		if (i == tgt)
			continue ;
		if (e->fds[i][IN] != e->fds[tgt][IN] && e->fds[i][IN] != e->fds[tgt][OUT] && e->fds[i][IN] != STDIN_FILENO)
			wclose(e->fds[i][IN], i, tgt);
		if (e->fds[i][OUT] != e->fds[tgt][IN] && e->fds[i][OUT] != e->fds[tgt][OUT] && e->fds[i][OUT] != STDOUT_FILENO)
			wclose(e->fds[i][OUT], i, tgt);
		if (i < tgt)
			e->node = e->node->sibling_next->sibling_next;
	}
	execute_text_tree_node(e);
	//wclose(e->fds[tgt][IN], tgt, tgt);
	//wclose(e->fds[tgt][OUT], tgt, tgt);
	return (0);
}

static int	close_fds()

static int	exec_chain(t_executor *e)
{
	t_treenode	*node;
	int			i;
	pid_t		pid;
	int			res;

	i = -1;
	node = e->node;
	while (++i < e->chain_length)
	{
		if (takes_part_in_pipe(node))
		{
			pid = fork();
			if (pid == -1)
				return (ft_assign_i(&e->errno, 1, 1));
			if (pid == 0)
				child(e, i);
			else
			{
				close_fds(e);
				res = parent(pid, &e->errno);
				return (ft_if_i(e->errno != 0, 1, res));
			}
		}
		if (node->sibling_next)
			node = node->sibling_next->sibling_next;
	}
	return (0);
}

static int	alloc(t_treenode *node, int ***fds, int *sz)
{
	int	i;

	*sz = 1;
	while (node && node->sibling_next && is_pipe_or_redir(node->sibling_next->content))
	{
		(*sz) ++;
		node = node->sibling_next->sibling_next;
	}
	*fds = ft_calloc_if(sizeof(int [2]) * (*sz), 1);
	if (!*fds)
		return (1);
	i = -1;
	while (++i < *sz)
	{
		(*fds)[i] = ft_calloc_if(sizeof(int) * 2, 1);
		if (!(*fds)[i])
		{
			while (--i >= 0)
				free((*fds)[i]);
			free(*fds);
			return (2);
		}
	}
	return (0);
}

int	setup_file(t_executor *e, t_treenode *node, int i)
{
	e->fds[i][OUT] = open(node->sibling_next->sibling_next->content,
		O_WRONLY | O_CREAT, 0600);
	if (e->fds[i][OUT] == -1)
		return (ft_assign_i(&e->errno, 2, 2));
	if (node->sibling_prev && is_redirection(node->sibling_prev->content))
	{
		close(e->fds[i][OUT]);
		e->fds[i + 1][IN] = e->fds[i - 1][IN];
		return (0);
	}
	e->fds[i + 1][IN] = e->fds[i][OUT];
	return (0);
}

/*
* not clear yet what to do with the first command of a chain,
* where is its input coming from... later
* */
int	redirections(t_executor *e)
{
	t_treenode	*node;
	int			i;
	int			p[2];

	if (alloc(e->node, &e->fds, &e->chain_length) != 0)
		return (ft_assign_i(&e->errno, 1, 1));
	node = e->node;
	i = -1;
	while (++i < e->chain_length)
	{
		e->fds[i][OUT] = OUT;
		if (i + 1 != e->chain_length)
			e->fds[i + 1][IN] = IN;
		if (node->sibling_next && is_pipe(node->sibling_next->content))
		{
			if (pipe(p) < 0)
				return (ft_assign_i(&e->errno, 2, 2));
			e->fds[i][OUT] = p[OUT];
			e->fds[i + 1][IN] = p[IN];
		}
		else if (node->sibling_next && setup_file(e, node, i) != 0)
			return (ft_assign_i(&e->errno, 3, 3));
		if (node->sibling_next)
			node = node->sibling_next->sibling_next;
	}
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FDS)
		ft_print_arr_i_2(e->fds, e->chain_length, 2);
	return (exec_chain(e));
}
