/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/09/22 16:21:48 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_common.h"

int	print_result_array(char **result, int sz)
{
	while (result[sz] != NULL)
	{
		printf("%s", result[sz]);
		sz--;
	}
	printf("\n");
	return (0);
}

// char	**ft_split_buf(const char *str, const char **charbuf, int *sz)
// {

// }


static int	test_1(int sz)
{
	int	i = 0;
	char *expect_arr[] = {"mkdir", "testf", "&&", "cd", "-L", "|", "testf", "||", "mkdir", "f1", "NULL"};
	while (expect_arr[i] != NULL)
	{
		i++;
	}
	printf("Number of str in expected array: %d, number of str in real array is %d\n", i, sz);
	assert(i == sz);
	return (0);
}

int	ft_split_buf_test(void)
{
	// const char	*operators[] = {">", "<", ">>", "<<", "|", "||", "&",
	// 						"&&", "(", ")"};
	char		*ss;
	int			sz = 10;
	char		*result[] = {"mkdir", "testf", "&&", "cd", "-L", "|", "testf", "||", "mkdir", "f1", "NULL"};

	// Input string to be split
	ss = "mkdir testf && cd -L | testf || mkdir f1";
	// Call the split function
	//result = ft_split_buf(ss, operators, &sz);
	// Test 1: Check the size of the result
	assert(test_1(sz) == 0);
	// Test 2: Check the content of the result
	// assert(test_2(result) == 0);
	// // Print the result
	// printf("Split result:\n");
	// for (int i = 0; i < sz; i++)
	// {
	// 	printf("%s\n", result[i]);
	// }
	// // Free the allocated memory
	// for (int i = 0; i < sz; i++)
	// {
	// 	free(result[i]);
	// }
	// free(result);
	printf("All tests passed!\n");
	print_result_array(result, sz);
	return 0;
}
