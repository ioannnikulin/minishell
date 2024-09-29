/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/30 00:30:21 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option_echo(int choice, t_treenode *node, t_param *param, char **out)
{
	if (!choice)
		return (0);
	(void)node;
	(void)param;
	*out = ft_strdup("echo");
	return (1);
}
