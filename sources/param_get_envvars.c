/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_get_envvars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:45:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 16:40:37 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	calc_len(const char *s, int *start, int *len_1, int *len_2)
{
	int	i;
	int	delim;

	i = 0;
	*len_1 = 0;
	*len_2 = 0;
	delim = 0;
	while (s[i])
	{
		if (s[i] == '=' && delim == 0)
		{
			delim = 1;
			*len_1 = i;
			i++;
			*start = i;
		}
		i++;
	}
	*len_2 = i - *len_1 + 1;
	return (0);
}

char	**split_env(char *s)
{
	int		key_start;
	int		len_1;
	int		len_2;
	char	**res;

	calc_len(s, &key_start, &len_1, &len_2);
	res = (char **)ft_calloc_if(sizeof(char *) * 3, 1);
	if (!res)
		return (NULL);
	res[0] = ft_substr(s, 0, len_1);
	res[1] = ft_substr(s, key_start, len_2);
	res[2] = NULL;
	if (!res[0] || !res[1])
	{
		ft_free_ss_uptonull((void **)res);
		return (NULL);
	}
	return (res);
}

static int	extract_path_env(t_param *param, char *s)
{
	int		sz;
	int		i;
	char	**tmp;

	sz = 0;
	i = 0;
	tmp = NULL;
	tmp = ft_split(s, ':', &sz);
	if (!tmp)
		return (1);
	while (tmp[i])
	{
		if (!ft_dlist_add_back_s(&param->envvar_path_head, tmp[i]))
		{
			ft_free_ss_uptonull((void **)tmp);
			return (1);
		}
		i++;
	}
	ft_free_ss_uptonull((void **)tmp);
	return (0);
}

static int	handle_envvar(t_param *param, char **s)
{
	if (ft_strncmp(s[0], "PATH", 4) == 0)
	{
		if (extract_path_env(param, s[1]))
			return (1);
	}
	else if (ft_strncmp(s[0], "PWD", 3) == 0)
		return (0);
	else if (ft_mapss_add(param->envvars, s[0], s[1]))
		return (1);
	return (0);
}

/* returns error code */
int	param_get_envvars(t_param *param, char **envp)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	while (envp[i])
	{
		tmp = split_env(envp[i]);
		if (!tmp || !tmp[0] || !tmp[1])
			return (1);
		if (handle_envvar(param, tmp))
		{
			ft_free_ss_uptonull((void **)tmp);
			return (1);
		}
		i++;
		ft_free_ss_uptonull((void **)tmp);
	}
	return (0);
}
