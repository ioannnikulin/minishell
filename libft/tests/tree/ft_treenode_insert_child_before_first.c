/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_insert_child_before_first.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:00:52 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/12 20:36:13 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

typedef s_testcase
{
	int	value;
	int exp_sz;
	int	exp[20];
}	t_testcase;

#define SZ 4

int	ft_treenode_insert_child_before_first_test(void)
{
	t_testcase t[SZ];
	t[0] = {5, 1, {5}};
	t[1] = {3, 2, {3, 5}};
	t[2] = {4, 3, {3, 4, 5}};
	t[3] = {6, 4, {3, 4, 5, 6}};
	
	t_treenode tgt = ft_treenode_make(ft_new_pi(-1), 0, 0, &ft_free_pi);
	for (int i = 0; i < SZ; i ++) {
		int ret = ft_treenode_insert_child_before_first(tgt, ft_treenode_make(ft_new_pi_pvoid(t[i].value), 0, 1, &ft_free_pi), t[i].idx);
		t_treenode *cur = tgt->child;
		int j = -1;
		while (++j < t[i].exp_sz && cur) {
			int	act = *(int*)cur->content;
			assert(act == t[i].exp[j]);
			cur = cur->sibling_next;
		}
		assert(j == t[i].exp_sz && !cur);
	}
	 return (0);
}
