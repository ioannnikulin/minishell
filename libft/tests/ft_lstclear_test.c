/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/21 19:04:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 9
#define DEBUG

typedef struct s_testcase
{
	int	end_to;
	char	*texts[20];
}	t_testcase;

void	ft_lstclear_test(void)
{
	t_list *root = ft_lstnew(ft_strdup("one"));
	root->next = ft_lstnew(ft_strdup("two"));
	root->next->next = ft_lstnew(ft_strdup("three"));
	ft_lstclear(&root, free);
}
