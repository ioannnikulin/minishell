/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:03:03 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/02 12:08:19 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"

int	unit_tests(void)
{
	printf("input_to_text_tree in progress\n");
	input_to_text_tree_test();
	ft_printf("input_to_text_tree tests completed\n");
	printf("split_str in progress\n");
	ft_split_str_test();
	ft_printf("ft_split_str_test completed\n");
	printf("tokenize_cmd in progress\n");
	tokenize_cmd_test();
	ft_printf("tokenize_cmd tests completed\n");
	printf("get_envvars in progress\n");
	get_envvars_test();
	ft_printf("get_envvars_test completed\n");
	return (0);
}
