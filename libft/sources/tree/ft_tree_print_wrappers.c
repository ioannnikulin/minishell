/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_print_wrappers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:11:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 22:36:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static char	*s(void *content)
{
	return ((char *)content);
}

int	ft_tree_print_s(t_tree *tree)
{
	return (ft_tree_print(tree, &s, "\t"));
}

static char	*c(void *content)
{
	return (content);
}

int	ft_tree_print_c(t_tree *tree)
{
	return (ft_tree_print(tree, &c, "\t"));
}
