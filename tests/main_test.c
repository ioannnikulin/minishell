/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:03:03 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/31 16:23:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"

int	main(void)
{
	printf("input_to_text_tree in testing\n");
	input_to_text_tree_test();
	printf("parsing in testing\n");
	parse_command_test();
	printf("\033[31mtesting complete\033[0m\n");
	return (0);
}
