/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 16:37:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ret(t_treenode *node, char *content, int retval)
{
	if (node && content)
		node->content = content;
	if (retval)
		ft_printf("%s: %s\n", TXT_MINISHELL, ERR_UNTERMINATED_BLOCK);
	return (retval);
}

static int	go(t_treenode *node, char *open, char *close)
{
	int		i;
	int		j;
	char	*content;

	i = 0;
	content = node->content;
	while (1)
	{
		while (content[i] && ft_strncmp(open, &content[i], ft_strlen(open)) != 0)
			i ++;
		if (!content[i])
			return (ret(node, content, 0));
		j = i + 1;
		while (content[j] && ft_strncmp(close, &content[j], ft_strlen(close)) != 0)
			j ++;
		if (!content[j])
			return (ret(0, 0, 1));
		if (!ft_replace_idx(&content, i, i + 1, "")
			|| !ft_replace_idx(&content, j - 1, j, ""))
			return (3);
	}
	return (0);
}

int	unpack_block(t_treenode *node, char *open, char *close)
{
	int	res;

	res = go(node, open, close);
	if (res)
		return (res);
	node = node->child;
	while (node)
	{
		res = go(node, open, close);
		if (res)
			return (res);
		node = node->sibling_next;
	}
	return (0);
}
