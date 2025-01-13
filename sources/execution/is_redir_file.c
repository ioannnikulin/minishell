/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:52:17 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 16:59:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	is_out_file(t_treenode *node)
{
	return (node->sibling_prev && is_to_out_redir(node->sibling_prev->content));
}

int	is_in_file(t_treenode *node)
{
	return (node->sibling_prev
		&& is_from_in_redir(node->sibling_prev->content));
}
