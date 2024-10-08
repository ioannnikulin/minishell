/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:44 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/02 22:56:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	option_pwd(int choice, t_treenode *node, t_param *param, char **out)
{
	if (!choice)
		return (0);
	(void)node;
	(void)param;
	*out = ft_strdup("pwd");
	return (1);
}