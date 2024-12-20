/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 17:06:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"
#include <sys/wait.h>

/*
* for builtins (not external) - set redirections up here
* externals with set them up in forks
* */
static int	builtin(int (*f)(t_executor *, t_treenode *, t_param *)
		, t_executor *executor)
{
	return (f(executor, executor->node, executor->param));
}

static int	chooser(t_executor *executor)
{
	char	*cmd;

	cmd = executor->node->content;
	if (ft_strcmp(cmd, "cd") == 0)
		builtin(option_cd, executor);
	else if (ft_strcmp(cmd, "echo") == 0)
		builtin(option_echo, executor);
	else if (ft_strcmp(cmd, "env") == 0)
		builtin(option_env, executor);
	else if (ft_strcmp(cmd, "exit") == 0)
		builtin(option_exit, executor);
	else if (ft_strcmp(cmd, "export") == 0)
		builtin(option_export, executor);
	else if (ft_strcmp(cmd, "pwd") == 0)
		builtin(option_pwd, executor);
	else if (ft_strcmp(cmd, "unset") == 0)
		builtin(option_unset, executor);
	else
		builtin(option_external, executor);
	return (0);
}

int	execute_text_tree_node(t_executor *e)
{
	t_tree	t;

	if (!e->node || !e->node->content)
		return (ft_printf("%s\n", ERR_NO_COMMAND_FOUND) * 0);
	if (expand(e->node, e->param))
		return (ft_assign_i(&e->param->opts.errno, 1, 0));
	t.root = e->node;
	if (e->param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_EXECUTION)
		ft_tree_print_s(&t);
	chooser(e);
	if (!e->found)
		printf("%s: %s\n", (char *)e->node->content, ERR_COMMAND_NOT_FOUND);
	return (e->retval);
}