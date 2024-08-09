/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environ_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/08/09 14:25:11 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

t_dlist	create_environ_list(t_params *params, t_dlist *node)
{
	t_dlist	*current;
	t_dlist	*tail;

	current = params->envvars.head;
	// Case 1: The list is empty
	if (current == NULL)
	{
		params->envvars.head = node;
		params->envvars.tail = node;
		node->next = NULL;
		node->prev = NULL;
		return (node);
	}
	// Case 2: Insert at the beginning (before the current head)
	if (ft_strcmp((node->content)->key, (current->content)->key) < 0)
	{
		node->next = current;
		node->prev = NULL;
		current->prev = node;
		params->envvars.head = node;
		return (node);
	}
	while (current != NULL)
	{
		//Case 3: Overwrite if key already exists
		if (ft_strcmp((node->content)->key, (current->content)->key) == 0)
		{
			free((current->content)->value); // Assuming value was dynamically allocated
			(current->content)->value = (node->content)->value;
			free((node->content)->key); // Free the old key if necessary
			free(node->content); // Free the new entry structure
			free(node); // Free the new node
			return (params->envvars.head); // No change to the list
		}
		else if (ft_strcmp((node->content)->key, (current->content)->key) > 0)
		{

		}
	}
}
