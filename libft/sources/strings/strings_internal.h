#ifndef STRINGS_INTERNAL_H
#define STRINGS_INTERNAL_H

#include <stddef.h>
#include <string.h>

#define MAX_OP 10

typedef struct s_operator
{
	char *op;
} t_operator;

typedef struct s_operator_array
{
	t_operator	*ops;
	size_t		count;
} t_operator_array;

typedef struct s_string
{
	char	*str;
} t_string;

typedef struct s_string_array
{
	t_string	*strs;
	size_t	count;
} t_string_array;


char	**ft_split_buf(const char *str, t_operator_array *op_array, int *sz);
#endif
