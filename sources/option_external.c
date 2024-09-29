/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:10:22 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/30 00:28:07 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option_external(int choice, t_treenode *node, t_param *param, char **out)
{
	if (!choice)
		return (0);
	(void)node;
	(void)param;
	*out = ft_strdup("external");
	return (1);
}
