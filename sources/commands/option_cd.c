/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:15 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 00:20:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static char	*get_checked_path(t_treenode *node, char *pwd, t_mapss *envvars)
{
	char	*tgt;

	if (!node->child)
		return (ft_strdup(ft_mapss_get(envvars, "HOME")));
	tgt = node->child->content;
	if (tgt[0] == '/')
	{
		if (access(tgt, X_OK) == 0)
			return (ft_strdup(tgt));
		return (0);
	}
	tgt = ft_strjoin_multi_free_outer(ft_s2(pwd, tgt), 2, "/");
	if (access(tgt, X_OK) == 0)
		return (tgt);
	free(tgt);
	return (0);
}

static int	couldnt(t_treenode *node, char *fullpath, int *ret)
{
	if (node->child)
		printf("cd: %s: %s\n", (char *)node->child->content, ERR_CD_NOWHERE);
	else
		printf("cd: %s\n", ERR_CD_NOWHERE);
	*ret = 1;
	free(fullpath);
	return (1);
}

// return value is ignored
// check on nonexisting folders
int	option_cd(t_control control, t_treenode *node, t_param *param)
{
	char	*fullpath;
	t_dlist	*envvars;

	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	fullpath = get_checked_path(node, param->envvar_path_head->content,
			&param->envvars);
	if (!fullpath || chdir(fullpath) != 0)
		return (couldnt(node, fullpath, control.retval));
	envvars = param->envvar_path_head->next;
	ft_dlist_delone(param->envvar_path_head, ft_free_s);
	param->envvar_path_head = envvars;
	param_get_cur_dir(param);
	*control.retval = 0;
	free(fullpath);
	return (1);
}
