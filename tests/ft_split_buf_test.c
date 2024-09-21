/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tree_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/09/21 12:56:25 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_common.h"

char	**ft_split_buf(const char *str, const char **charbuf, int *sz)
{

}

int	ft_split_buf_test(void)
{
	const char	*operators[] = {">", "<", ">>", "<<", "|", "||", "&",
							"&&", "(", ")"};
	char		*ss;
	int			sz;
	char		**result;

	sz = 0;
	ss = "mkdir testf && cd -L | testf || mkdir f1";
	result = ft_split(ss, operators, &sz);
	while (result[sz] != NULL)
	{
		printf("%s", result[sz]);
		sz--;
	}
	printf("\n");
	return (0);
}
