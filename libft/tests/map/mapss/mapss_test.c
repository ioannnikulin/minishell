/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapss_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 10:00:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss_test.h"

extern int memcheck_enabled;
void	mapss_test(void)
{
	ft_printf("mapss: gen in testing\n");
	ft_mapss_gen_test();
	ft_printf("mapss: get in testing\n");
	ft_mapss_get_test();
	ft_printf("mapss: print in testing\n");
	ft_mapss_print_test();
	ft_printf("mapss: ncmp in testing\n");
	ft_mapss_ncmp_test();
	ft_printf("mapss: del in testing\n");
	ft_mapss_del_test();
	if (!memcheck_enabled)
	{
		ft_printf("mapss: add in testing\n");
		ft_mapss_add_test();
	}
	return ;
}
