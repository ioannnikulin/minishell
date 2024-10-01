/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/09/30 10:53:43 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_common.h"

int find_operator(const char *str, operator_array *op_array, size_t *op_len)
{
	for (size_t i = 0; i < op_array->count; i++)
	{
		size_t	len = strlen(op_array->operators[i].operator);
		// Compare the operator with the current substring
		if (ft_strncmp(str, op_array->operators[i].operator, len) == 0)
		{
			*op_len = len;  // Length of the matched operator
			return (1); // Operator found
		}
	}
	*op_len = 0;
	return (0);  // No operator found
}

static void	extract_word(char **res, const char **str, operator_array *op_array)
{
	size_t	op_len;

	// Check if the current position is an operator
	if (find_operator(*str, op_array, &op_len))
	{
		// Allocate memory and store the operator in the result array
		*res = (char *) ft_calloc_if((op_len + 1) * sizeof(char), 1);
		if (*res == 0)
			return;
		ft_strncpy(*res, *str, op_len);
		(*res)[op_len] = '\0';  // Null-terminate the operator string
		*str += op_len;         // Move the string pointer forward by operator length
	}
	else
	{
		// Allocate memory for the regular word until the next operator
		size_t		word_len = 0;
		const char	*start = *str;
		// Count characters until the next operator or end of the string
		while (**str && !find_operator(*str, op_array, &op_len))
		{
			(*str)++;
			word_len++;
		}

		if (word_len == 0)
			return;
		// Allocate memory and store the word in the result array
		*res = (char *) ft_calloc_if((word_len + 1) * sizeof(char), 1);
		if (*res == 0)
			return;
		strncpy(*res, start, word_len);
		(*res)[word_len] = '\0';  // Null-terminate the word
	}
}

static int	calc_words(const char *pp, operator_array *op_array)
{
	int		word_qtty = 0;
	const	char *p = pp;
	size_t	op_len;

	while (*p)
	{
		// Check if the current position matches any operator
		if (find_operator(p, op_array, &op_len))
		{
			word_qtty++;	// Counting the operator as a separate word
			p += op_len;   // Move pointer forward by the length of the operator
		}
		else
		{
			// If it's not an operator, scan through the characters until the next delimiter
			while (*p && !find_operator(p, op_array, &op_len))
				p++;
			word_qtty++;  // Counting the word before the operator
		}
	}
	return (word_qtty);
}

static int	check_edges(char **res, int *cwi)
{
	if (!res[*cwi])
	{
		while (-- (*cwi) > -1)
			free(res[*cwi]);
		free(res);
		return (1);
	}
	if (!res[*cwi][0])
	{
		free(res[*cwi]);
		(*cwi)--;
	}
	return (0);
}

// Function to count the number of words based on the operators
char	**ft_split_buf(const char *str, operator_array *op_array, int *sz)
{
	char **res = NULL;
	int word_qtty;
	int cwi;

	// Count the total number of words and operators
	word_qtty = calc_words(str, op_array);
	if (sz)
		*sz = -1;
	//Allocate memory for the result array
	res = (char **) ft_calloc_if((word_qtty + 1) * sizeof(char *), 1);
	if (!res)
		return (0);
	res[word_qtty] = 0;  // Null-terminate the array
	if (word_qtty == 0)
		return (res);
	cwi = 0;
	while (*str && cwi < word_qtty)
	{
		extract_word(&res[cwi], &str, op_array);
		if (check_edges(res, &cwi))
			return (0);
		cwi++;
	}
	if (sz)
		*sz = word_qtty;
	return (res);
}
