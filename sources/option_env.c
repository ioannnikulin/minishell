/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:59 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/30 00:30:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option_env(int choice, t_treenode *node, t_param *param, char **out)
{
	if (!choice)
		return (0);
	(void)node;
	(void)param;
	*out = ft_strdup("env");
	return (1);
}
