/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:04:08 by inikulin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/15 22:47:06 by inikulin         ###   ########.fr       */
=======
/*   Updated: 2024/12/22 10:36:37 by taretiuk         ###   ########.fr       */
>>>>>>> github/dev
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_INTERNAL_H
# define TESTS_INTERNAL_H
# include "../sources/minishell.h"
# include <assert.h>
# include <fcntl.h>
# include <regex.h>
# include <stddef.h>

int	    input_to_text_tree_test(void);
int		expand_tree_test(void);
void    tokenize_cmd_test(void);
void	tokens_to_tree_test(void);
void	ft_split_str_test(void);
int		get_envvars_test(void);

#endif
