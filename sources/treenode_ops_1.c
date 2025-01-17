/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treenode_ops_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:10:25 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 23:46:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_txt(void *content)
{
	t_command	*cmd;

	cmd = content;
	return (cmd->txt);
}

int	cmd_cmp(void *a, void *b)
{
	return (ft_strcmp(cmd_txt(a), cmd_txt(b)));
}
