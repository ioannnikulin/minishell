/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:54:57 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/03 17:59:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	mbzero(void *obj, int bytes, int retval)
{
	char	*char_obj;
	
	if (!obj || bytes <= 0)
		return (retval);
	char_obj = obj;
	while (--bytes)
		char_obj[bytes] = 0;
	return (retval);
}

int	mfree(int choice, void **obj, int bytes, int ret)
{
	if (!choice)
		return (ret);
	mbzero(*obj, bytes, 0);
	free(obj);
	return (ret);
}
