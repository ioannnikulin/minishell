/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_processing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:20:07 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/14 08:01:16 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_PROCESSING_H
# define TREE_PROCESSING_H
# include "../minishell.h"
# include "tree_processing_internal.h"

int	tokens_to_tree(t_tree *tree, char **tokens);

#endif