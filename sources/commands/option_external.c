/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:10:22 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/11 19:50:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static char	*find_executable(char *tgt, t_dlist *path)
{
	char	*fullpath;

	while (path)
	{
		fullpath = ft_strjoin_multi_free_outer(ft_s2(path->content, tgt), 2, "/");
		if (access(fullpath, X_OK) == 0)
			return (fullpath);
		free(fullpath);
		path = path->next;
	}
	return (0);
}

static int	run_executable(char *fullpath, t_param *param)
{
	char	*argv[2];

	argv[0] = fullpath;
	argv[1] = 0;
	return (execve(fullpath, argv, get_envvars_for_execve(param)));
}

/* test with empty path, found in first, found in last, not found,
 * found but not allowed, empty command */
int	option_external(int choice, t_treenode *node, t_param *param,
					t_execution_result *res)
{
	char	*fullpath;

	if (!choice)
		return (0);
	if (param->debug_output_level & DBG_EXTERNAL_SEARCH_FOLDERS)
	{
		printf("searching for command in folders:\ncurrent\n");
		ft_dlist_print_s(param->envvar_path_head, "\n");
	}
	fullpath = find_executable(node->content, param->envvar_path_head);
	if (!fullpath)
		return (0);
	res->retval = run_executable(fullpath, param);
	res->output = ft_strdup(fullpath);
	free(fullpath);
	return (1);
}
