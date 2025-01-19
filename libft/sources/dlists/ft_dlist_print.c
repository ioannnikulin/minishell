/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/06 22:59:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	node_and_check(t_dlist *cur, int debug_lvl, void (*p)(void *))
{
	int	ret;

	ret = 0;
	if (cur->prev != 0 && cur->prev->next != cur)
		ret = 1;
	if (cur->next != 0 && cur->next->prev != cur)
		ret = 1;
	if ((debug_lvl & ANGLES) > 0)
		FT_PRINTF("< ");
	if ((debug_lvl & PREV) > 0)
		FT_PRINTF("(%p) ", cur->prev);
	if ((debug_lvl & ADDR) > 0)
		FT_PRINTF("[%p] ", cur);
	p(cur->content);
	if ((debug_lvl & NEXT) > 0)
		FT_PRINTF(" (%p)", cur->next);
	if ((debug_lvl & ANGLES) > 0)
		FT_PRINTF(" >");
	return (ret);
}

static int	print_check(t_dlist *err, int debug_lvl)
{
	if ((debug_lvl & NEWLINE_BEFORE_CHECK) > 0)
		FT_PRINTF("\n");
	if (err)
	{
		FT_PRINTF("First inconsistency in links found at object %p\n", err);
		return (1);
	}
	FT_PRINTF("Link incosistencies not found\n");
	return (0);
}

static void	prints(void *p)
{
	FT_PRINTF("%s", (char *)p);
}

int	ft_dlist_print_s(t_dlist *lst, char *delim)
{
	return (ft_dlist_print(lst, 0, delim, prints));
}

int	ft_dlist_print(t_dlist *lst, int dbg, char *delim, void (*p)(void *))
{
	t_dlist	*cur;
	int		lstlen;
	t_dlist	*err;

	lstlen = ft_dlist_size(lst);
	cur = lst;
	err = 0;
	while (-- lstlen >= 0)
	{
		if (node_and_check(cur, dbg, p) && !err)
			err = cur;
		FT_PRINTF("%s", delim);
		cur = cur->next;
	}
	if ((dbg & CHECK) > 0)
		return (print_check(err, dbg));
	return (0);
}
