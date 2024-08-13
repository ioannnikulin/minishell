/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_add_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/13 22:45:57 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss.h"

void	ft_mapss_add_test(void)
{
	int		result;
	t_mapss	*map;

	 // Define arrays of keys and values
	const char *keys[] = {"PATH", "SHELL", "HOME", "USERNAME", "PATH", "SHLVL", "OLDPWD", "DISPLAY", ""};
	const char *values[] = {"/usr/local/sbin", "/bin/bash", "/home/user", "/usr/local/sbin", "1", "/home/taretiuk/42/student",
							":0", "X Window", "Error"};
	int num_entries = sizeof(keys) / sizeof(keys[0]);
	result = 0;

	// Loop through keys and values arrays
	for (int i = 0; i < num_entries; i++)
		ft_mapss_add(map, keys[i], values[i]);
	ft_printf("Environment list:\n");
	ft_mapss_print(map);
}
