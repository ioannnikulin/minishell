/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbuf_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:19:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 18:51:25 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_internal.h"
//#define DEBUG
#define START 0
#define SZ 2

typedef struct s_testcase
{
	char	*src;
	int		adds;
	char	*add[10];
	char	*exp[10];
	int		expsz[10];
	int		expcap[10];
}	t_testcase;

int	ft_sbuf_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"a", 2, {"bcbcbcbcbcbcbcbc", "dededededededededededede"}, {"a", "abcbcbcbcbcbcbcbc", "abcbcbcbcbcbcbcbcdededededededededededede"}, {1, 17, 31}, {20, 20, 40}};
	t[1] = (t_testcase){0, 2, {"", 0}, {"", "", ""}, {0, 0, 0}, {20, 20, 20}};
	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		ft_printf("== %i ==\n", i);
		#endif
		t_sbuf *sbuf = ft_sbuf_make(t[i].src);
		assert(sbuf && sbuf->content);
		for (int j = 0; j < t[i].adds; j ++)
		{
			#ifdef DEBUG
			ft_printf("-- %i --\n", j);
			#endif
			if (j > 0)
				assert(ft_sbuf_append(sbuf, t[i].add[j - 1]) == sbuf);
			char *get = ft_sbuf_get(sbuf);
			int getlen = ft_strlen(get);
			assert(t[i].expsz[j] == getlen && getlen == sbuf->sz);
			assert(ft_strcmp(t[i].exp[j], get) == 0);
			assert(t[i].expcap[j] == sbuf->capacity);
			free(get);
		}
		ft_sbuf_finalize(&sbuf);
	}
	return (0);
}
