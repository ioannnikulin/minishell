/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_insert_child_before_first_test.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:00:52 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 13:45:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_internal.h"
//#define DEBUG

typedef struct s_testcase
{
	int	value;
	int exp_sz;
	int	exp[20];
	int	exp_ret;
}	t_testcase;

#define SZ 4

int	ft_treenode_insert_child_before_first_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){5, 1, {5}, 0};
	t[1] = (t_testcase){3, 2, {3, 5}, 0};
	t[2] = (t_testcase){4, 3, {3, 4, 5}, 1};
	t[3] = (t_testcase){6, 4, {3, 4, 5, 6}, 3};
	
	t_treenode *tgt = ft_treenode_make(ft_new_pi(-1), 0, &ft_free_pi_null);
	for (int i = 0; i < SZ; i ++) {
		#ifdef DEBUG
		FT_PRINTF("%i: ", i);
		#endif
		int ret = ft_treenode_insert_child_before_first(tgt, ft_treenode_make(ft_new_pi_pvoid(t[i].value), 0, &ft_free_pi_null), &ft_less_eq_pvoid_pi);
		t_treenode *cur = tgt->child;
		int j = -1;
		while (++j < t[i].exp_sz && cur) {
			int	act = *(int*)cur->content;
			#ifdef DEBUG
			FT_PRINTF("%i %i; ", t[i].exp[j], act);
			#endif
			assert(act == t[i].exp[j]);
			cur = cur->sibling_next;
		}
		#ifdef DEBUG
		FT_PRINTF("\n");
		#endif
		assert(tgt->children_qtty == j && j == t[i].exp_sz && !cur);
		#ifdef DEBUG
		FT_PRINTF("%i %i\n", t[i].exp_ret, ret);
		#endif
		assert(t[i].exp_ret == ret);
	}
	ft_treenode_free_rec(&tgt);
	return (0);
}
