/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:46:13 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 18:25:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	scroll_chain(t_executor *e, int tgt)
{
	while (tgt-- > 0)
		e->node = e->node->sibling_next->sibling_next;
	return (0);
}

t_treenode	*prev_command(t_executor *e, t_treenode *node)
{
	(void)e;
	(void)node;
	return (0);
}