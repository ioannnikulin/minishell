/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:03:03 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/03 15:56:48 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"

int	unit_tests(void)
{
	printf("input_to_text_tree in progress\n");
	input_to_text_tree_test();
	ft_printf("input_to_text_tree tests completed\n");
	printf("tokenize_cmd in progress\n");
	tokenize_cmd_test();
	ft_printf("tokenize_cmd tests completed\n");
	return (0);
}
