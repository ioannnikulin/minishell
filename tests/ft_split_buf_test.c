/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/09/23 12:34:17 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_common.h"

static int	test_2(char **str_1, char **str_2, int sz_1)
{
	for (int i = 0; i < sz_1; i++)
	{
		printf("%s\n", str_1[i]);
		printf("%s\n", str_2[i]);
		assert(ft_strcmp(str_1[i], str_2[i]) == 0);
	}
	return (0);
}


static int	test_1(int sz_1, int sz_2)
{
	printf("size of expected array: %d, size of str in real array is %d\n",
			sz_1, sz_2);
	assert(sz_1 == sz_2);
	return (0);
}

static char	**generate_test_1(int *sz)
{
	size_t	size = 0;
	int	count = 0, i =0;
	static char *test_arr[] = {"mkdir", "testf", "&&", "cd", "-L", "|", "testf",
			"||", "mkdir", "f1"};

	size = sizeof(test_arr)/sizeof(char *);
	for (i = 0; i < (int)size; i++)
	{
		printf("%d - %s, ", count + 1, *(test_arr+i));
		count++;
	}
	*sz = count;
	return (test_arr);
}

int	ft_split_buf_test(void)
{
	int		sz_1 = 10;
	int		sz_2 = 0;
	//char	*ss = "mkdir testf && cd -L | testf || mkdir f1";
	char	*result_arr[] = {"mkdir", "testf", "&&", "cd", "-L", "|", "testf",
			"||", "mkdir", "f1"};
	char	**expect_arr = generate_test_1(&sz_2);
	// Call the split function
	//result_arr = ft_split_buf(ss, operators, &sz_1);
	// Test 1: Check the size of the result
	assert(test_1(sz_1, sz_2) == 0);
	// Test 2: Check the content of the result
	assert(test_2(result_arr, expect_arr, sz_1) == 0);
	// Print the result
	// printf("Split result:\n");
	// for (int i = 0; i < sz_2; i++)
	// {
	// 	printf("%s\n", expect_arr[i]);
	// }
	// // Free the allocated memory
	// for (int i = 0; i < sz; i++)
	// {
	// 	free(result[i]);
	// }
	// free(result);
	return 0;
}
