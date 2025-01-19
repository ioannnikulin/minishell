/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_cut_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:00:52 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/13 12:31:51 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_internal.h"
#define SZ 9
#define START 0
//#define DEBUG

typedef struct s_testcase
{
	int	src[20];
	int	src_sz;
	int	fromIncl;
	int	toExcl;
	int	exp_left[20];
	int	exp_left_sz;
	int	exp_ret[20];
	int	exp_ret_sz;
}	t_testcase;

static int	cmp(int exp[], int exp_sz, t_treenode *act)
{
	if (exp_sz == 0)
	{
		#ifdef DEBUG
		FT_PRINTF("expected empty\n");
		#endif
		assert(act == 0);
	}
	else
	{
		int j = -1;
		while (++j < exp_sz && act) {
			int	act_i = *(int*)act->content;
			#ifdef DEBUG
			FT_PRINTF("%i %i; ", exp[j], act_i);
			#endif
			assert(exp[j] == act_i);
			act = act->sibling_next;
		}
		#ifdef DEBUG
		FT_PRINTF("\n");
		#endif
		assert(j == exp_sz && !act);
	}
	return (0);
}

int	ft_treenode_cut_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 0, 8, {}, 0, {0, 1, 2, 3, 4, 5, 6, 7}, 8};
	t[1] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 0, 0, {0, 1, 2, 3, 4, 5, 6, 7}, 8, {}, 0};
	t[2] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 10, 11, {0, 1, 2, 3, 4, 5, 6, 7}, 8, {}, 0};
	t[3] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 2, 4, {0, 1, 4, 5, 6, 7}, 6, {2, 3}, 2};
	t[4] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 4, 2, {0, 1, 2, 3, 4, 5, 6, 7}, 8, {}, 0};
	t[5] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 0, 4, {4, 5, 6, 7}, 4, {0, 1, 2, 3}, 4};
	t[6] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 4, 8, {0, 1, 2, 3}, 4, {4, 5, 6, 7}, 4};
	t[7] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 4, 10, {0, 1, 2, 3}, 4, {4, 5, 6, 7}, 4};
	t[8] = (t_testcase){{0, 1, 2, 3, 4, 5, 6, 7}, 8, 0, 10, {}, 0, {0, 1, 2, 3, 4, 5, 6, 7}, 8};
	
	for (int i = START; i < SZ; i ++) {
		#ifdef DEBUG
		FT_PRINTF("===%i===\n", i);
		#endif
		t_treenode *tgt = ft_treenode_make(ft_new_pi(-1), 0, &ft_free_pi_null);
		for (int j = 0; j < t[i].src_sz; j ++)
			assert(ft_treenode_insert_child_idx(tgt, ft_treenode_make(ft_new_pi_pvoid(t[i].src[j]), 0, &ft_free_pi_null), j) == j);
		t_treenode *cut = ft_treenode_cut(tgt, t[i].fromIncl, t[i].toExcl);
		#ifdef DEBUG
		FT_PRINTF("returned cutout: ");
		#endif
		cmp(t[i].exp_ret, t[i].exp_ret_sz, cut);
		#ifdef DEBUG
		FT_PRINTF("leftover: ");
		#endif
		cmp(t[i].exp_left, t[i].exp_left_sz, tgt->child);
		ft_treenode_free_rec(&tgt);
		ft_treenode_free_rec(&cut);
	}
	return (0);
}
