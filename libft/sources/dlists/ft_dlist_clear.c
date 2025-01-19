/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 18:30:37 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_dlist_clear(t_dlist **lst, void (*del)(void *), int ret)
{
	t_dlist	*cur;
	t_dlist	*n;
	int		lstlen;

	if (!lst || !(*lst))
		return (ret);
	lstlen = ft_dlist_size(*lst);
	cur = *lst;
	while (lstlen --)
	{
		n = cur->next;
		if (del)
			del(cur->content);
		free(cur);
		cur = n;
	}
	*lst = 0;
	return (ret);
}

static void	free_s_p(void *c)
{
	char	*cc;

	if (!c)
		return ;
	cc = c;
	free(cc);
}

int	ft_dlist_clear_s(t_dlist **lst, int ret)
{
	return (ft_dlist_clear(lst, free_s_p, ret));
}

static void	free_pi(void *c)
{
	int	*cc;

	if (!c)
		return ;
	cc = c;
	free(cc);
}

int	ft_dlist_clear_i(t_dlist **lst, int ret)
{
	return (ft_dlist_clear(lst, free_pi, ret));
}
