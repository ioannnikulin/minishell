/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:58:25 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 17:17:51 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_assign_i(int *where, int what, int retval)
{
	if (where)
		*where = what;
	return (retval);
}

char	*ft_assign_i_pc(int *where, int what, char *retval)
{
	if (where)
		*where = what;
	return (retval);
}

int	ft_assign_pc(char **where, char *what, int retval)
{
	if (where)
		*where = what;
	return (retval);
}

int	ft_assign_sz(size_t *where, size_t what, int retval)
{
	if (where)
		*where = what;
	return (retval);
}
