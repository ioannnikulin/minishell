/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/17 13:06:09 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ceil(float a)
{
	int	i;

	i = a;
	if (a < 0)
	{
		if (a > i)
			return (i + 1);
		return (i);
	}
	if (a > i)
		return (i + 1);
	return (i);
}

int	ft_floor(float a)
{
	int	i;

	i = a;
	if (a < 0 && a != i)
		return (i - 1);
	return (i);
}
