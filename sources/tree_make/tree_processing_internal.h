/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_processing_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:55:53 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/03 14:50:35 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_PROCESSING_INTERNAL_H
# define TREE_PROCESSING_INTERNAL_H

# include "tree_processing.h"

int	is_closing_parenthesis(char *token);
int	is_opening_parenthesis(char *token);
int	is_operator(char *token);
int	is_redirection(char *token);
int	process_operator(char *token, t_treenode **cur_1, int *num);
int	process_open_parentheses(char *token, t_treenode **cur_1,
		t_treenode **cur_2, int *num);
int	process_closing_parentheses(t_treenode **cur_1, t_treenode **cur_2,
		int *num);
int	process_cmd_and_flag(char *token, t_treenode **cur_1,
		t_treenode **cur_2, int *num);

#endif
