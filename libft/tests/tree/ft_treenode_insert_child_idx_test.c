/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_insert_child_idx_test.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:00:52 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/12 22:31:51 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_internal.h"
//#define DEBUG

typedef struct s_testcase
{
	int	value;
	int	idx;
	int	exp_sz;
	int	exp[20];
	int	exp_ret;
}	t_testcase;

#define SZ 8

int	ft_treenode_insert_child_idx_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){5, 2, 1, {5}, 0};
	t[1] = (t_testcase){3, 0, 2, {3, 5}, 0};
	t[2] = (t_testcase){4, 1, 3, {3, 4, 5}, 1};
	t[3] = (t_testcase){1, -2, 4, {1, 3, 4, 5}, 0};
	t[4] = (t_testcase){0, -1, 5, {0, 1, 3, 4, 5}, 0};
	t[5] = (t_testcase){2, 4, 6, {0, 1, 3, 4, 2, 5}, 4};
	t[6] = (t_testcase){6, 6, 7, {0, 1, 3, 4, 2, 5, 6}, 6};
	t[7] = (t_testcase){7, 10, 8, {0, 1, 3, 4, 2, 5, 6, 7}, 7};
	
	t_treenode *tgt = ft_treenode_make(ft_new_pi(-1), 0, &ft_free_pi_null);
	for (int i = 0; i < SZ; i ++) {
		#ifdef DEBUG
		FT_PRINTF("%i: ", i);
		#endif
		int ret = ft_treenode_insert_child_idx(tgt, ft_treenode_make(ft_new_pi_pvoid(t[i].value), 0, &ft_free_pi_null), t[i].idx);
		t_treenode *cur = tgt->child;
		int j = -1;
		while (++j < t[i].exp_sz && cur) {
			int	act = *(int*)cur->content;
			#ifdef DEBUG
			FT_PRINTF("%i %i; ", t[i].exp[j], act);
			#endif
			assert(t[i].exp[j] == act);
			cur = cur->sibling_next;
		}
		#ifdef DEBUG
		FT_PRINTF("\n");
		#endif
		assert(tgt->children_qtty == j && j == t[i].exp_sz && !cur);
		assert(t[i].exp_ret == ret);
	}
	ft_treenode_free_rec(&tgt);
	return (0);
}
