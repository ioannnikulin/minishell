/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:18:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/01 19:06:50 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_(char *s1, char *s2, char *ret)
{
	free(s1);
	free(s2);
	return (ret);
}

char	*ft_replace_idx(char **where, int fromIncl, int toExcl, char *with)
{
	char	*before_s;
	char	*after_s;
	int		where_len;
	char	*res;

	if (!where || !*where || !with)
		return (0);
	where_len = ft_strlen(*where);
	if (fromIncl < 0 || fromIncl > where_len || toExcl > where_len)
		return (0);
	if (fromIncl >= toExcl)
		return (*where);
	before_s = ft_substr(*where, 0, fromIncl);
	after_s = ft_substr(*where, toExcl, ft_strlen(*where) - toExcl + 1);
	if (!before_s || !after_s)
		return (free_(before_s, 0, 0));
	res = ft_strjoin_multi_free_outer(ft_s3(before_s, with, after_s), 3, "");
	if (!res)
		return (free_(before_s, after_s, 0));
	free(*where);
	*where = res;
	return (free_(before_s, after_s, *where));
}