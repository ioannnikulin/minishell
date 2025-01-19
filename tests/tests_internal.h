/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:04:08 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 18:17:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_INTERNAL_H
# define TESTS_INTERNAL_H
# include "../sources/minishell.h"
# include <assert.h>
# include <fcntl.h>
# include <regex.h>
# include <sys/wait.h>

int	    input_to_text_tree_test(void);
int		expand_tree_test(void);
void    tokenize_cmd_test(void);
void	tokens_to_tree_test(void);
void	ft_split_str_test(void);
int		get_envvars_test(void);

#endif
