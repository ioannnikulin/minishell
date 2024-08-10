/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:54:57 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 17:48:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free(int choice, void **obj, int bytes, int ret)
{
	if (!choice || !obj || !*obj)
		return (ret);
	ft_bzero(*obj, bytes);
	free(*obj);
	*obj = 0;
	return (ret);
}
