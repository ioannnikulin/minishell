/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:10:22 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 23:55:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static char	*find_executable(char *tgt, t_dlist *path, int *errno)
{
	char	*fullpath;

	while (path)
	{
		fullpath = ft_strjoin_multi_free_outer(
				ft_s2(path->content, tgt), 2, "/");
		if (!fullpath)
		{
			ft_assign_i(errno, 4, 0);
			return (0);
		}
		if (access(fullpath, X_OK) == 0)
			return (fullpath);
		free(fullpath);
		path = path->next;
	}
	return (0);
}

static int	run_executable(char *fullpath, t_treenode *node, t_param *param)
{
	char	**argv;
	int		argc;
	int		i;
	char	**envvars;

	argc = node->children_qtty;
	argv = ft_calloc_if(sizeof(char *) * (argc + 2), 1);
	if (!argv)
		return (ft_assign_i(&param->errno, 5, 0));
	argv[0] = fullpath;
	argv[argc + 1] = 0;
	i = 1;
	node = node->child;
	while (i <= argc)
	{
		argv[i ++] = node->content;
		node = node->sibling_next;
	}
	envvars = get_envvars_for_execve(param);
	if (param->errno)
		return (0);
	i = w_execve(fullpath, argv, envvars, &param->errno);
	free(argv);
	free(envvars);
	return (i);
}

/* test with empty path, found in first, found in last, not found,
 * found but not allowed, empty command */
int	option_external(t_control control, t_treenode *node, t_param *param)
{
	char	*fullpath;

	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	if (param->debug_output_level & DBG_EXTERNAL_SEARCH_FOLDERS)
	{
		printf("searching for command in folders:\n");
		ft_dlist_print_s(param->envvar_path_head, "\n");
	}
	fullpath = find_executable(node->content, param->envvar_path_head,
			&param->errno);
	if (!fullpath)
		return (0);
	*control.retval = run_executable(fullpath, node, param);
	free(fullpath);
	if (!param->errno)
		return (0);
	printf("%s: ERROR %i\n", (char *)node->content, param->errno);
	return (0);
}
