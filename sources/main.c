/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/22 16:06:41 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	t_param	param;

	(void)argv;
	if (init_param(&param))
		return (1);
	if (argc == 1)
	{
		printf("Starting interactive mode\n");
	}
	else
	{
		printf("Starting non-interactive mode\n");
	}
}
