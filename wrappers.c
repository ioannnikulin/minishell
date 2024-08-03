/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:14:30 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/03 17:15:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	terminate(t_params *params, int mode, char *message, int retval)
{
	return (finalize(params, mode, message, retval));
}
