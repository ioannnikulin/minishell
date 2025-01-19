/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_get_envvars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:45:38 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 20:21:36 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	split_env(char *s, char **key, char **value)
{
	int	i;

	i = -1;
	*key = s;
	*value = 0;
	while (s[++i])
	{
		if (s[i] == '=')
		{
			s[i] = 0;
			*value = &s[i + 1];
			return (0);
		}
	}
	return (1);
}

static int	extract_path_env(t_param *param, char *s)
{
	char	*start;
	char	*current;

	start = s;
	while (*start)
	{
		current = start;
		while (*start && *start != ':')
			start++;
		if (*start == ':')
		{
			*start = '\0';
			start++;
		}
		if (!ft_dlist_add_back_s(&param->envvar_path_head, current))
			return (1);
		start --;
		*start = ':';
		start ++;
	}
	return (0);
}

static int	handle_envvar(t_param *param, char *key, char *value)
{
	if (ft_strncmp(key, "PATH", 5) == 0)
	{
		if (extract_path_env(param, value))
			return (1);
	}
	else if (ft_mapss_add(param->envvars, key, value))
		return (1);
	return (0);
}

/* returns error code */
int	param_get_envvars(t_param *param, char **envp)
{
	int		i;
	char	*key;
	char	*val;

	i = 0;
	while (envp[i])
	{
		split_env(envp[i], &key, &val);
		if (handle_envvar(param, key, val))
			return (1);
		envp[i][ft_strlen(key) + 1] = '=';
		i++;
	}
	return (0);
}
