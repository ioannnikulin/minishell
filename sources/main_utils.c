/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:25:19 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/18 19:11:29 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	usage(void)
{
	FT_PRINTF("minishell usage:\n--interactive\n\tuser types in a command after command.\n\
--debug 1023\n\tbitmask for debug output verbosity.\n\
--command echo hello world\n\trun just one command and exit immediately.\n\
--trap 5\n\tmalloc with given number will fail. debugging option.\n\
--file script.sh\n\trun commands from given file.\n");
}
