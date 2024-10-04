#ifndef STRINGS_INTERNAL_H
#define STRINGS_INTERNAL_H

# include <stddef.h>
# include <stdlib.h>
# include "strings.h"
# include "../memory/memory.h"

#define MAX_OP 10

typedef struct s_delim
{
	char *delim;
} t_delim;

typedef struct s_delims
{
	t_delim		*delims;
	size_t		count;
} t_delims;

typedef struct s_string
{
	char	*str;
} t_string;

typedef struct s_string_array
{
	t_string	*strs;
	size_t	count;
} t_strings;


char	**ft_split_buf(const char *s, void *delim_arr, int *sz);
int		find_delimiter(const char *s, t_delims *array, size_t *op_len);
int		extract_plain_token(char **res, const char **s, t_delims *array, int cwi);
int		extract_delimiter(char **res, const char **s, size_t op_len, int cwi);
#endif