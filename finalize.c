/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:11:19 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/03 18:01:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	finalize(t_params *params, int mode, char *message, int retval)
{
	t_dlist	*current_node;
	t_dlist	*node_to_free;

	if (params)
	{
		if ((mode & FREE_ENVVARS_DLISTS) || (mode & FREE_ENVVARS_ENTRIES) || (mode & FREE_ENVVARS_KEYS) || (mode & FREE_ENVVARS_VALUES))
		{
			current_node = params->envvars->head;
			while (current_node)
			{
				node_to_free = current_node;
				current_node = current_node->next;
				mfree(mode & FREE_ENVVARS_KEYS, &node_to_free->content->key, sizeof(char*), 0);
				mfree(mode & FREE_ENVVARS_VALUES, &node_to_free->content->value, sizeof(char*), 0);
				mfree(mode & FREE_ENVVARS_ENTRIES, &node_to_free->content, sizeof(t_envvar*), 0);
				mfree(mode & FREE_ENVVARS_NODES, &node_to_free, sizeof(t_dlist*), 0);
			}
		}
	}
}
