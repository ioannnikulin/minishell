/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/07 14:51:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_control	make_ctrl(int *retval, int *found)
{
	t_control	res;

	res.retval = retval;
	res.found = found;
	*retval = 0;
	*found = 0;
	return (res);
}

static int	switch(t_param *param, t_treenode *node, t_control *control)
{
	char	*cmd;

	cmd = node->content;
	if ()
	option_cd(control(is(cmd, "cd", 3), &res, &found), node, param);
	option_echo(control(is(cmd, "echo", 5), &res, &found), node, param);
	option_env(control(is(cmd, "env", 4), &res, &found), node, param);
	option_exit(control(is(cmd, "exit", 5), &res, &found), node, param);
	option_export(control(is(cmd, "export", 7), &res, &found), node, param);
	option_pwd(control(is(cmd, "pwd", 4), &res, &found), node, param);
	option_unset(control(is(cmd, "unset", 6), &res, &found), node, param);
	option_external(control(!found, &res, &found), node, param);
}

int	execute_text_tree_node(t_param *param, t_treenode *node)
{
	t_tree	t;
	t_control	ctrl;

	if (!node || !node->content)
		return (ft_printf("%s\n", ERR_NO_COMMAND_FOUND) * 0);
	if (expand(node, param))
		return (ft_assign_i(&param->opts.errno, 1, 0));
	t.root = node;
	if (param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_EXECUTION)
		ft_tree_print_s(&t);
	ctrl = control();
	if (!found)
		printf("%s: %s\n", cmd, ERR_COMMAND_NOT_FOUND);
	return (res);
}
