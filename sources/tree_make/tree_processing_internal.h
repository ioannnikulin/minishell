/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_processing_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:55:53 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/14 07:56:30 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_PROCESSING_INTERNAL_H
# define TREE_PROCESSING_INTERNAL_H

#include "tree_processing.h"

int	is_operator(char *token);
int	is_redirection(char *token);

#endif