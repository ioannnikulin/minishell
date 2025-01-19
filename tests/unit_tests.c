/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:03:03 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 20:22:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"

int	unit_tests(void)
{
	FT_PRINTF("input_to_text_tree in progress\n");
	input_to_text_tree_test();
	FT_PRINTF("input_to_text_tree tests completed\n");
	FT_PRINTF("split_str in progress\n");
	ft_split_str_test();
	FT_PRINTF("ft_split_str_test completed\n");
	FT_PRINTF("tokenize_cmd in progress\n");
	tokenize_cmd_test();
	FT_PRINTF("tokenize_cmd tests completed\n");
	FT_PRINTF("expand_tree in progress\n");
	expand_tree_test();
	FT_PRINTF("expand_tree tests completed\n");
	FT_PRINTF("get_envvars in progress\n");
	get_envvars_test();
	FT_PRINTF("get_envvars_test completed\n");
	return (0);
}
