/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_common.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:04:08 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/23 18:13:24 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_COMMON_H
# define TESTS_COMMON_H
# include "../sources/minishell.h"
# include <assert.h>
# include <string.h>

#define MAX_OPERATORS 10

typedef struct
{
	char *operator;
} operator;

typedef struct
{
	operator	*operators;
	size_t		count;
} operator_array;

typedef struct
{
	char	*string;
} string;

typedef struct
{
	string	*strings;
	size_t	count;
} string_array;

char	**ft_split_buf(const char *str, operator_array *op_array, int *sz);
void	ft_split_buf_test(void);
int		input_to_text_tree_test(void);
#endif
