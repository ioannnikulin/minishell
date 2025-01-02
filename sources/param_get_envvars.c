/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_get_envvars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:45:38 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/02 16:08:49 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	calc_len(const char *s, int *start, int *len_1, int *len_2)
{
	int	i;

	i = 0;
	*len_1 = 0;
	*len_2 = 0;
	while (s[i])
	{
		if (s[i] == '=')
		{
			*len_1 = i + 1;
			*start = i + 1;
			break ;
		}
		i++;
	}
	while (s[i])
		i++;
	*len_2 = i - *start;
	return (0);
}

void	split_env(char *s, char *key, char *value)
{
	int			val_start;
	int			key_len;
	int			val_len;

	calc_len(s, &val_start, &key_len, &val_len);
	ft_strlcpy(key, s, key_len);
	ft_strcpy(value, s + val_start);
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
	else if (ft_strncmp(key, "PWD", 4) == 0)
		return (0);
	else if (ft_mapss_add(param->envvars, key, value))
		return (1);
	return (0);
}

/* returns error code */
int	param_get_envvars(t_param *param, char **envp)
{
	int		i;
	char	key[256];
	char	val[256];

	i = 0;
	while (envp[i])
	{
		split_env(envp[i], key, val);
		if (handle_envvar(param, key, val))
			return (1);
		i++;
	}
	return (0);
}
