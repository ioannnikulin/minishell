/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 21:09:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_control	control(int choice, int *retval, int *found)
{
	t_control	res;

	res.choice = choice;
	res.retval = retval;
	res.found = found;
	return (res);
}

static int	is(char *a, char *b, int c)
{
	return (ft_strncmp(a, b, c) == 0);
}

int	execute_text_tree_node(t_param *param, t_treenode *node)
{
	int		res;
	char	*cmd;
	int		found;
	t_tree	t;

	if (!node || !node->content)
		return (printf("%s\n", ERR_NO_COMMAND_FOUND) * 0);
	if (expand(node, param))
		return (ft_assign_i(&param->opts.errno, 1, 0));
	cmd = node->content;
	t.root = node;
	if (param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_EXECUTION)
		ft_tree_print_s(&t);
	ft_assign_i(&found, 0, ft_assign_i(&res, 0, 0));
	option_cd(control(is(cmd, "cd", 3), &res, &found), node, param);
	option_echo(control(is(cmd, "echo", 5), &res, &found), node, param);
	option_env(control(is(cmd, "env", 4), &res, &found), node, param);
	option_exit(control(is(cmd, "exit", 5), &res, &found), node, param);
	option_export(control(is(cmd, "export", 7), &res, &found), node, param);
	option_pwd(control(is(cmd, "pwd", 4), &res, &found), node, param);
	option_unset(control(is(cmd, "unset", 6), &res, &found), node, param);
	option_external(control(!found, &res, &found), node, param);
	if (!found)
		printf("%s: %s\n", cmd, ERR_COMMAND_NOT_FOUND);
	return (res);
}
