/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treenode_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:32:49 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 13:57:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_command_null(void **c)
{
	t_command	*cmd;

	cmd = *c;
	cmd->free_txt((void **)&cmd->txt);
	free(cmd);
	*c = 0;
}

t_treenode	*treenode_make(char *token, t_treenode *p,
	void (*free_token)(void **))
{
	t_command	*cmd;
	t_treenode	*node;

	cmd = ft_calloc_if(sizeof(t_command), 1);
	if (!cmd)
	{
		free_token((void **)&token);
		return (0);
	}
	cmd->txt = token;
	cmd->free_txt = free_token;
	cmd->in_fd = STDIN;
	cmd->out_fd = STDOUT;
	node = ft_treenode_make(cmd, p, free_command_null);
	if (!node)
	{
		free_token((void **)&token);
		free(cmd);
		return (0);
	}
	return (node);
}

static int	treenode_insert(t_treenode *parent, char *token,
	void (*free_token)(void **), int idx)
{
	t_treenode	*node;

	node = treenode_make(token, parent, free_token);
	if (!node)
		return (-1);
	return (ft_treenode_insert_child_idx(parent, node, idx));
}

int	treenode_insert_dup(t_treenode *parent, char *token, int idx)
{
	char	*s;

	s = ft_strdup(token);
	if (!s)
		return (-1);
	return (treenode_insert(parent, s, ft_free_s_null, idx));
}

int	treenode_insert_nop(t_treenode *parent, char *token, int idx)
{
	return (treenode_insert(parent, token, ft_free_nop, idx));
}