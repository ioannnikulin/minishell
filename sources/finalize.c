/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:11:19 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 17:49:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	finalize(t_param *param, int mode, char *message, int retval)
{
	t_dlist	*current_node;
	t_dlist	*node_to_free;
	t_envvar	*content;

	if (param)
	{
		if ((mode & FREE_ENVVARS_DLISTS) || (mode & FREE_ENVVARS_ENTRIES) || (mode & FREE_ENVVARS_KEYS) || (mode & FREE_ENVVARS_VALUES))
		{
			current_node = param->envvars.head;
			while (current_node)
			{
				node_to_free = current_node;
				current_node = current_node->next;
				content = node_to_free->content;
				ft_free(mode & FREE_ENVVARS_KEYS, (void**)&content->key, sizeof(char*), 0);
				ft_free(mode & FREE_ENVVARS_VALUES, (void**)&content->value, sizeof(char*), 0);
				ft_free(mode & FREE_ENVVARS_ENTRIES, &node_to_free->content, sizeof(t_envvar*), 0);
				ft_free(mode & FREE_ENVVARS_DLISTS, (void**)&node_to_free, sizeof(t_dlist*), 0);
			}
		}
	}
	if (message)
		ft_printf(message);
	return (retval);
}
