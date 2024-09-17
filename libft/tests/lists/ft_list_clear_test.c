/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 12:04:54 by inikulin         ###   ########.fr       */
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

void	ft_list_clear_test(void)
{
	t_list *root = ft_list_new(ft_strdup("one"));
	root->next = ft_list_new(ft_strdup("two"));
	root->next->next = ft_list_new(ft_strdup("three"));
	ft_list_clear(&root, free);
}
