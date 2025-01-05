/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapss_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 11:35:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss_test.h"

extern int memcheck_enabled;
void	mapss_test(void)
{
	FT_PRINTF("mapss: gen in testing\n");
	ft_mapss_gen_test();
	FT_PRINTF("mapss: get in testing\n");
	ft_mapss_get_test();
	FT_PRINTF("mapss: print in testing\n");
	ft_mapss_print_test();
	FT_PRINTF("mapss: ncmp in testing\n");
	ft_mapss_ncmp_test();
	FT_PRINTF("mapss: del in testing\n");
	ft_mapss_del_test();
	FT_PRINTF("mapss: add in testing\n");
	ft_mapss_add_test();
	return ;
}
