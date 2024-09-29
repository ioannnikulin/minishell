/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:30 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/30 00:29:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option_export(int choice, t_treenode *node, t_param *param, char **out)
{
	if (!choice)
		return (0);
	(void)node;
	(void)param;
	*out = ft_strdup("export");
	return (1);
}
