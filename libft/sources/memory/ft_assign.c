/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:58:25 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/25 00:07:17 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
