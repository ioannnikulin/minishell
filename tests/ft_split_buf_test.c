/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/09/30 10:49:49 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_common.h"

// static int	test_2(char **str_1, char **str_2, int sz_1)
// {
// 	for (int i = 0; i < sz_1; i++)
// 	{
// 		printf("%s\n", str_1[i]);
// 		printf("%s\n", str_2[i]);
// 		assert(ft_strcmp(str_1[i], str_2[i]) == 0);
// 	}
// 	return (0);
// }


// static int	test_1(int sz_1, int sz_2)
// {
// 	printf("size of expected array: %d, size of str in real array is %d\n",
// 			sz_1, sz_2);
// 	assert(sz_1 == sz_2);
// 	return (0);
// }

// static char	**generate_test_1(int *sz)
// {
// 	size_t	size = 0;
// 	int	count = 0, i =0;
// 	static char *test_arr[] = {"mkdir", "testf", "&&", "cd", "-L", "|", "testf",
// 			"||", "mkdir", "f1"};

// 	size = sizeof(test_arr)/sizeof(char *);
// 	for (i = 0; i < (int)size; i++)
// 	{
// 		printf("%d - %s, ", count + 1, *(test_arr+i));
// 		count++;
// 	}
// 	*sz = count;
// 	return (test_arr);
// }

string_array	create_string_array()
{
	string_array	str_array;
	str_array.count = 10;
	str_array.strings = (string *)malloc(str_array.count * sizeof(string));

	str_array.strings[0].string = "ls -la > output.txt";
	str_array.strings[1].string = "cat < input.txt && echo | grep \"Done\"";
	str_array.strings[2].string = "grep \"error\" log.txt || echo \"No errors found\"";
	str_array.strings[3].string = "gcc main.c -o program >> build.log";
	str_array.strings[4].string = "find . -name \"*.txt\" | xargs rm -rf || fer && def & echo \"Hello\"";
	str_array.strings[5].string = "echo \"Compiling...\" && gcc main.c -o program && ./program";
	str_array.strings[6].string = "cd folder";
	str_array.strings[7].string = "mkdir new_dir && cd new_dir && touch file.txt";
	str_array.strings[8].string = "command1 > out.txt && command2 < in.txt || echo \"Error\"";
	str_array.strings[9].string = "cat ( file1.txt file2.txt ) | grep \"keyword\"";
	str_array.strings[10].string = " 0";
	return (str_array);
}

operator_array create_operator_array()
{
	operator_array op_array;
	op_array.count = 10;
	op_array.operators = (operator *) malloc(op_array.count * sizeof(operator));

	op_array.operators[0].operator = ">>";
	op_array.operators[1].operator = ">";
	op_array.operators[2].operator = "<<";
	op_array.operators[3].operator = "<";
	op_array.operators[4].operator = "||";
	op_array.operators[5].operator = "|";
	op_array.operators[6].operator = "&&";
	op_array.operators[7].operator = "&";
	op_array.operators[8].operator = "(";
	op_array.operators[9].operator = ")";

	return (op_array);
}

void	ft_split_buf_test(void)
{
	int				sz_1 = 0;
	operator_array 	op_ar = create_operator_array();
	string_array	str_arr = create_string_array();
	//char			**expect_arr = generate_test_1(&sz_2);

	for (int i = 0; i < (int)str_arr.count; i++)
	{
		char **delim_operator = ft_split_buf(str_arr.strings[i].string, &op_ar, &sz_1);
		printf("Test %i: %s\n", i, str_arr.strings[i].string);
		for (int j = 0; j < sz_1; j++)
		{
			printf("Token %d: %s\n", j, delim_operator[j]);
			free(delim_operator[j]);  // Free each token after use
		}
		printf("\n");
		free(delim_operator);  // Free the array of pointers itself
	}
	// Free the string entries in the string_array
	for (int i = 0; i < (int)str_arr.count; i++)
	{
		free(str_arr.strings[i].string);
	}
	free(str_arr.strings);  // Free the string array itself
	free(op_ar.operators);  // Free the operator array
	// assert(test_1(input, sz_1) == 0);
	// // Test 2: Check the content of the result
	// //assert(test_2(result, expect_arr, sz_2) == 0);
}
