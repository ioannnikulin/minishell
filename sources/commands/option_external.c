/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:10:22 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/19 12:41:15 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include <sys/stat.h>

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

static char	**get_argv(char *fullpath, t_treenode *node)
{
	char	**argv;
	int		argc;
	int		i;

	argc = node->children_qtty;
	argv = ft_calloc_if(sizeof(char *) * (argc + 2), 1);
	if (!argv)
		return (0);
	argv[0] = fullpath;
	argv[argc + 1] = 0;
	i = 1;
	node = node->child;
	while (i <= argc)
	{
		argv[i ++] = *get_node_txt(node);
		node = node->sibling_next;
	}
	return (argv);
}

static int	check_isdir(char *fullpath, t_param *param, t_treenode *node)
{
	struct stat	statbuf;

	if (stat(fullpath, &statbuf) != 0)
		return (ft_assign_i(&param->opts.errno, 6, 6));
	if ((statbuf.st_mode & S_IFMT) == S_IFDIR)
	{
		ERR("%s: %s: %s\n", TXT_MINISHELL, *get_node_txt(node),
			ERR_CANNOT_EXECUTE_A_DIRECTORY);
		return (126);
	}
	return (0);
}

static int	run_executable(char *fullpath, t_treenode *node, t_param *param)
{
	char		**argv;
	int			ret;
	char		**envvars;

	ret = check_isdir(fullpath, param, node);
	if (ret)
		return (ret);
	argv = get_argv(fullpath, node);
	if (!argv)
		return (ft_assign_i(&param->opts.errno, 5, 0));
	envvars = get_envvars_for_execve(param);
	if (param->opts.errno)
	{
		free(argv);
		return (0);
	}
	ret = w_execve(fullpath, argv, envvars, param);
	free(argv);
	ft_free_ss_uptonull_null((void ***)&envvars);
	return (ret);
}

/* test with empty path, found in first, found in last, not found,
 * found but not allowed, empty command */
int	option_external(t_executor *control, t_treenode *node, t_param *param)
{
	char	*fullpath;
	t_dlist	*search;

	control->found = 1;
	search = param->envvar_pwd;
	search->next = param->envvar_root;
	search->next->next = param->envvar_path_head;
	if (param->opts.debug_output_level & DBG_EXTERNAL_SEARCH_FOLDERS)
	{
		FT_PRINTF("searching for command in folders:\n");
		ft_dlist_print_s(search, "\n");
		FT_PRINTF("--\n");
	}
	fullpath = find_executable(*get_node_txt(node), search, &param->opts.errno);
	param->envvar_pwd->next = 0;
	param->envvar_root->next = 0;
	if (!fullpath)
		return (ft_assign_i(&control->found, 0, 0));
	control->retval = run_executable(fullpath, node, param);
	free(fullpath);
	if (!param->opts.errno)
		return (0);
	ERR("%s: ERROR %i\n", *get_node_txt(node), param->opts.errno);
	return (0);
}
