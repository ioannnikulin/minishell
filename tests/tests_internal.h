/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:04:08 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/11 02:05:51 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_COMMON_H
# define TESTS_COMMON_H
# include "../sources/minishell.h"
# include <assert.h>
# include <fcntl.h>
# include <regex.h>

int	    input_to_text_tree_test(void);
void    tokenize_cmd_test(void);

#endif
