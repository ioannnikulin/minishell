/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:03:03 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/08 12:38:57 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"

int	unit_tests(void)
{
	printf("input_to_text_tree in testing\n");
	input_to_text_tree_test();
	printf("tokenization in testing\n");
	tokenize_cmd_test();
	return (0);
}
