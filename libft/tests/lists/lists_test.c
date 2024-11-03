/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 14:27:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_internal.h"
#include "lists_test.h"

int	lists_test(void)
{
	printf("list_new in testing\n");
	ft_list_new_test();
	printf("list_size in testing\n");
	ft_list_size_test();
	printf("list_add_front in testing\n");
	ft_list_add_front_test();
	printf("list_last in testing\n");
	ft_list_last_test();
	printf("list_add_back in testing\n");
	ft_list_add_back_test();
	printf("list_delone in testing\n");
	ft_list_delone_test();
	printf("list_map in testing\n");
	ft_list_map_test();
	printf("list_iter in testing\n");
	ft_list_iter_test();
	printf("list_generate in testing\n");
	ft_list_generate_test();
	printf("All tests passed successfully!\n");
	return (0);
}
