/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:37:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/24 00:38:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*trim(char *s)
{
	int		f;
	int		t;
	char	*res;

	t = ft_strlen(s) - 1;
	while (s[t] == '\n' || s[t] == '\r' || s[t] == ' ')
		t --;
	f = 0;
	while (s[f] == '\n' || s[f] == '\r' || s[f] == ' ')
		f ++;
	res = ft_calloc_if(sizeof(char) * (t - f + 2), 1);
	if (!res)
		return (res);
	ft_strlcpy(res, &s[f], t + 2);
	free(s);
	return (res);
}

/* returns error code */
int	history_add(t_param *param, char *s)
{
	t_history_entry	*entry;

	entry = ft_calloc_if(sizeof(t_history_entry), 1);
	if (!entry)
		return (1);
	entry->text = trim(s);
	entry->prev = param->history.last;
	if (param->history.last)
		param->history.last->next = entry;
	param->history.last = entry;
	return (0);
}
