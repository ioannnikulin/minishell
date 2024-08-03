/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 11:35:17 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	phase1(t_list *lst, t_list **meet)
{
	t_list	*fast;
	t_list	*slow;
	int		len;

	fast = lst->next->next;
	slow = lst->next;
	len = 2;
	while (fast != slow && fast != 0 && fast->next != 0)
	{
		fast = fast->next->next;
		slow = slow->next;
		len += 2;
	}
	if (fast == 0)
		return (len);
	if (fast->next == 0)
		return (len + 1);
	*meet = fast;
	return (-len);
}

static int	phase2(t_list *slow1, t_list *slow)
{
	int	len;

	len = 1;
	while (slow != slow1)
	{
		slow1 = slow1->next;
		slow = slow->next;
		len ++;
	}
	while (slow->next != slow1)
	{
		slow = slow->next;
		len ++;
	}
	return (len);
}

int	ft_list_size(t_list *lst)
{
	t_list	*meet;
	int		len;

	if (lst == 0)
		return (0);
	if (lst->next == 0)
		return (1);
	if (lst->next->next == 0)
		return (2);
	len = phase1(lst, &meet);
	if (len > 0)
		return (len);
	return (phase2(lst, meet));
}
