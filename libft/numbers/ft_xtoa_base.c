/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:36:51 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/24 18:07:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h" 
#define MX 65 
#define MAXBASE 256

static size_t	cut_n_put(unsigned long long nb, char *sym,
		int base, char *digits)
{
	int	cur_dig;
	int	neg;

	cur_dig = MX - 1;
	neg = 0;
	if (base < 0)
	{
		neg = 1;
		base = -base;
	}
	while (nb > 0)
	{
		(digits)[cur_dig --] = sym[nb % base];
		nb = nb / base;
	}
	if (neg)
		(digits)[cur_dig --] = '-';
	return (MX - 1 - cur_dig);
}

static int	check_base(char *base)
{
	size_t	baselen;
	size_t	prev;

	baselen = 0;
	while (base[baselen])
	{
		if (base[baselen] == '+' || base[baselen] == '-')
			return (0);
		prev = 0;
		while (prev < baselen)
		{
			if (base[prev] == base[baselen])
				return (0);
			prev ++;
		}
		baselen ++;
	}
	if (baselen < 2 || baselen > MAXBASE)
		return (0);
	return ((int)baselen);
}

size_t	ft_ulltoa_base(unsigned long long nbr, char *base, char *buf)
{
	size_t	res;
	int		baselen;
	int		i;

	baselen = check_base(base);
	if (baselen == 0)
		return (0);
	if (nbr == 0)
	{
		buf[MX - 1] = *base;
		return (1);
	}
	if (nbr <= LLONG_MAX)
		return (cut_n_put(nbr, base, baselen, buf));
	res = cut_n_put(nbr / baselen, base, baselen, buf);
	i = MX - res - 1;
	while (i < MX - 1)
	{
		buf[i] = (buf)[i + 1];
		i ++;
	}
	(buf)[i] = base[nbr % baselen];
	return (res + 1);
}

size_t	ft_lltoa_base(long long nbr, char *base, char *buf)
{
	unsigned long long	unb;
	int					baselen;

	ft_bzero(buf, MX);
	baselen = check_base(base);
	if (baselen == 0)
		return (0);
	if (nbr == 0)
	{
		(buf)[MX - 1] = *base;
		return (1);
	}
	unb = nbr;
	if (nbr < 0)
	{
		unb = -nbr;
		baselen = -baselen;
	}
	return (cut_n_put(unb, base, baselen, buf));
}
