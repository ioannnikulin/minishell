/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/12 20:11:48 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

static int	builtin(int (*f)(t_control *, t_treenode *, t_param *)
				, t_control *control, t_treenode *node, t_param *param)
{
	return (f(control, node, param));
}

static int	chooser(t_param *param, t_treenode *node, t_control *control)
{
	char	*cmd;

	cmd = node->content;
	if (ft_strcmp(cmd, "cd") == 0)
		builtin(option_cd, control, node, param);
	else if (ft_strcmp(cmd, "echo") == 0)
		builtin(option_echo, control, node, param);
	else if (ft_strcmp(cmd, "env") == 0)
		builtin(option_env, control, node, param);
	else if (ft_strcmp(cmd, "exit") == 0)
		builtin(option_exit, control, node, param);
	else if (ft_strcmp(cmd, "export") == 0)
		builtin(option_export, control, node, param);
	else if (ft_strcmp(cmd, "pwd") == 0)
		builtin(option_pwd, control, node, param);
	else if (ft_strcmp(cmd, "unset") == 0)
		builtin(option_unset, control, node, param);
	else
		builtin(option_external, control, node, param);
	return (0);
}

int	execute_text_tree_node(t_param *param, t_treenode *node, t_control *ctrl)
{
	t_tree	t;

	if (!node || !node->content)
		return (ft_printf("%s\n", ERR_NO_COMMAND_FOUND) * 0);
	if (expand(node, param))
		return (ft_assign_i(&param->opts.errno, 1, 0));
	t.root = node;
	if (param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_EXECUTION)
		ft_tree_print_s(&t);
	chooser(param, node, ctrl);
	if (!ctrl->found)
		printf("%s: %s\n", (char *)node->content, ERR_COMMAND_NOT_FOUND);
	return (ctrl->retval);
}
