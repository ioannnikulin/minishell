/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_print_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:33:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/20 23:17:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++ i < argc)
		printf("%s\n", argv[i]);
	system("printenv");
	return (0);
}
