/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:52:17 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:49:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	is_to_out_redir(char *c)
{
	return (ft_strcmp(c, ">") == 0 || ft_strcmp(c, ">>") == 0);
}

int	is_from_in_redir(char *c)
{
	return (ft_strcmp(c, "<") == 0);
}

int	is_heredoc(char *c)
{
	return (ft_strcmp(c, "<<") == 0);
}
