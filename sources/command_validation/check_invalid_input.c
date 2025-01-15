/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:03:08 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/15 19:13:59 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_validation_internal.h"

int	print_err_message(char *error, char *token, int i, int ret)
{
	if (i == 0)
		FT_FPRINTF(STDERR, "%s: %s '%s'\n", TXT_MINISHELL, error, token);
	return (ret);
}

bool	check_consequent_tokens(char *s1, char *s2)
{
	if ((is_operator(s1) || is_redirection(s1)
			|| is_opening_parenthesis(s1) || is_closing_parenthesis(s1))
		&& (is_operator(s2) || is_redirection(s2)
			|| is_opening_parenthesis(s2) || is_closing_parenthesis(s2)))
		return (print_err_message(ERR_UNEXPECTED_TOKEN, s1, 0, 0));
	return (true);
}

bool	check_first_node(char *s)
{
	if (is_operator(s) || is_redirection(s)
		|| is_closing_parenthesis(s) || is_opening_parenthesis(s))
		return (print_err_message(ERR_UNEXPECTED_TOKEN, s, 0, 0));
	return (true);
}

bool	check_invalid_input(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (i == 0 && !check_first_node(tokens[i]))
			return (0);
		else if (tokens[i + 1] != NULL)
		{
			if (!check_consequent_tokens(tokens[i], tokens[i + 1]))
				return (0);
		}
		i++;
	}
	return (true);
}
