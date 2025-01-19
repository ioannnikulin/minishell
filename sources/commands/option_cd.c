/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:15 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 20:29:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static char	*home(t_mapss *envvars, int *errno)
{
	char	*tgt;

	tgt = ft_mapss_get(envvars, "HOME");
	if (!tgt)
		return (ft_assign_i_pc(errno, 1, 0));
	tgt = ft_strdup(tgt);
	if (!tgt)
		return (ft_assign_i_pc(errno, 2, 0));
	return (tgt);
}

static char	*get_checked_path(t_treenode *node, char *pwd, t_mapss *envvars,
		int *errno)
{
	char	*tgt;

	if (!node->child)
		return (home(envvars, errno));
	tgt = *get_node_txt(node->child);
	if (tgt[0] == '/')
	{
		if (access(tgt, X_OK) == 0)
		{
			tgt = ft_strdup(tgt);
			if (!tgt)
				ft_assign_i(errno, 3, 0);
			return (tgt);
		}
		return (ft_assign_i_pc(errno, 4, 0));
	}
	tgt = ft_strjoin_multi_free_outer(ft_s2(pwd, tgt), 2, "/");
	if (!tgt)
		return (ft_assign_i_pc(errno, 5, 0));
	if (access(tgt, X_OK) == 0)
		return (tgt);
	free(tgt);
	return (ft_assign_i_pc(errno, 6, 0));
}

static int	couldnt(t_treenode *node, char *fullpath, int *ret, int errno)
{
	if (errno == 4 || errno == 6 || errno == 0)
		ERR("%s: cd: %s: %s\n",
			TXT_MINISHELL, *get_node_txt(node->child), ERR_CD_NOWHERE);
	else if (errno == 1)
		ERR("%s: cd: %s\n",
			TXT_MINISHELL, ERR_CD_NO_HOME);
	else if (errno == 7)
		ERR("%s: cd: %s\n", TXT_MINISHELL, ERR_CD_TOO_MANY_ARGS);
	else
		ERR("%s: cd: %s\n", TXT_MINISHELL, ERR_MALLOC);
	*ret = 1;
	free(fullpath);
	return (1);
}

// return value is ignored
// check on nonexisting folders
// check on unset HOME
int	option_cd(t_executor *control, t_treenode *node, t_param *param)
{
	char	*fullpath;
	int		errno;

	control->found = 1;
	if (node->child && node->child->sibling_next)
		return (couldnt(0, 0, &control->retval, 7));
	errno = 0;
	fullpath = get_checked_path(node, param->envvar_pwd->content,
			param->envvars, &errno);
	if (!fullpath || chdir(fullpath) != 0)
		return (couldnt(node, fullpath, &control->retval, errno));
	free(fullpath);
	if (ft_mapss_get(param->envvars, "OLDPWD") && ft_mapss_add(param->envvars,
			"OLDPWD", param->envvar_pwd->content))
		return (ft_assign_i(&param->opts.errno, 1, 1));
	ft_dlist_delone(param->envvar_pwd, ft_free_s);
	param_get_cur_dir(param);
	if (ft_mapss_get(param->envvars, "PWD") && ft_mapss_add(param->envvars,
			"PWD", param->envvar_pwd->content))
		return (ft_assign_i(&param->opts.errno, 2, 2));
	control->retval = 0;
	return (1);
}
