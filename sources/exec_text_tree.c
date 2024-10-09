/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/02 15:06:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*execute_text_tree_node(t_param *param, t_treenode *node)
{
	char	*out;
	char	*cmd;

	cmd = node->content;
	out = 0;
	option_cd(ft_strncmp(cmd, "cd", 3) == 0, node, param, &out);
	option_echo(!out && ft_strncmp(cmd, "echo", 5) == 0, node, param, &out);
	option_env(!out && ft_strncmp(cmd, "env", 4) == 0, node, param, &out);
	option_exit(!out && ft_strncmp(cmd, "exit", 5) == 0, node, param, &out);
	option_export(!out && ft_strncmp(cmd, "export", 7) == 0, node, param, &out);
	option_pwd(!out && ft_strncmp(cmd, "pwd", 4) == 0, node, param, &out);
	option_unset(!out && ft_strncmp(cmd, "unset", 6) == 0, node, param, &out);
	option_external(!out, node, param, &out);
	if (!out)
		printf("%s: %s\n", cmd, ERR_COMMAND_NOT_FOUND);
	else
		printf("%s\n", out);
	return (out);
}

int	exec_text_tree(t_param *param)
{
	char	*res;

	ft_tree_print_s(param->text_tree);
	if (!param || !param->text_tree || !param->text_tree->root)
	{
		printf("%s\n", ERR_TEXT_TREE_EMPTY);
		return (1);
	}
	res = execute_text_tree_node(param, param->text_tree->root->child);
	free(res);
	return (0);
}
