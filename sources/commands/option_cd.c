/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:15 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/05 20:31:32 by inikulin         ###   ########.fr       */
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
	tgt = node->child->content;
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
		w_perror(ft_s7(ft_s4(TXT_MINISHELL, ": cd: ",
					node->child->content, ": "), ERR_CD_NOWHERE, "\n", 0));
	else if (errno == 1)
		w_perror(ft_s5(ft_s4(TXT_MINISHELL, ": cd: ",
					ERR_CD_NO_HOME, "\n"), 0));
	else if (errno == 7)
		w_perror(ft_s5(ft_s4(TXT_MINISHELL, ": cd: ",
					ERR_CD_TOO_MANY_ARGS, "\n"), 0));
	else
		w_perror(ft_s5(ft_s4(TXT_MINISHELL, ": cd: ",
					ERR_MALLOC, "\n"), 0));
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
	t_dlist	*envvars;
	int		errno;

	control->found = 1;
	if (node->child && node->child->sibling_next)
		return (couldnt(0, 0, &control->retval, 7));
	errno = 0;
	fullpath = get_checked_path(node, param->envvar_path_head->content,
			param->envvars, &errno);
	if (!fullpath || chdir(fullpath) != 0)
		return (couldnt(node, fullpath, &control->retval, errno));
	envvars = param->envvar_path_head->next;
	ft_dlist_delone(param->envvar_path_head, ft_free_s);
	param->envvar_path_head = envvars;
	envvars->prev = 0;
	param_get_cur_dir(param);
	control->retval = 0;
	free(fullpath);
	return (1);
}
