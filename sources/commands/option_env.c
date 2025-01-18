/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:59 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 19:47:09 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	usr_bin_is_in_path(t_param *param)
{
	t_dlist	*node;

	node = param->envvar_path_head;
	while (node)
	{
		if (ft_strcmp(node->content, "/usr/bin") == 0)
			return (1);
		node = node->next;
	}
	return (0);
}

// return value is ignored
// well, what did you expect? env in bash is not a builtin
int	option_env(t_executor *control, t_treenode *node, t_param *param)
{
	char	**lines;
	int		i;

	control->found = 1;
	(void)node;
	if (!usr_bin_is_in_path(param))
	{
		ERR("%s: env: %s\n", TXT_MINISHELL, ERR_WHY_DID_YOU_UNSET_PATH);
		control->retval = 127;
		return (1);
	}
	lines = get_envvars_for_execve(param);
	if (!lines)
	{
		ERR("env: %s\n", ERR_MALLOC);
		return (1);
	}
	i = -1;
	while (lines[++ i])
		FT_PRINTF("%s\n", lines[i]);
	ft_free_ss_uptonull_null((void ***)&lines);
	control->retval = 0;
	return (1);
}
