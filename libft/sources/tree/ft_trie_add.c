/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:31:24 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/04 20:19:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"


int	ft_tree_apply(t_tree *tgt, int (*check)(t_treenode*), int (*apply)(t_treenode*),
				t_tree_traversal_mode mode);

