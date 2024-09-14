/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 19:29:40 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cmp_pvoid_pi(void *a, void *b)
{
	int	aa;
	int	bb;

	aa = *(int*)a;
	bb = *(int*)b;
	return (aa - bb);
}

int	ft_less_eq_pvoid_pi(void *a, void *b)
{
	return (ft_cmp_pvoid_pi(a, b) <= 0);
}
