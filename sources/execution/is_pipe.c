/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:33:24 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	is_pipe(char *c)
{
	return (ft_strcmp(c, "|") == 0);
}

int	is_pipe_or_redir(char *c)
{
	return (is_pipe(c) || is_redirection(c));
}

int from_pipe(t_treenode *node)
{
	return (node->sibling_prev && is_pipe(node->sibling_prev->content));
}

int to_pipe(t_treenode *node)
{
	return (node->sibling_next && is_pipe(node->sibling_next->content));
}

int	takes_part_in_pipe(t_treenode *node)
{
	return (to_pipe(node) || from_pipe(node));
}