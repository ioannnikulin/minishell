/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:55:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/30 16:32:30 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <stddef.h>
# include "../../libft.h"

typedef struct s_delim
{
	char	*delim;
}	t_delim;

typedef struct s_delims
{
	t_delim		*delims;
	int			error;
	size_t		count;
}	t_delims;

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_multi(const char **ss, int sz, const char *delim);
char	*ft_strjoin_multi_free_outer(char **ss, int sz, const char *delim);
char	*ft_strjoin_multi_free_full(char **ss, int sz, const char *delim);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char delim, int *sz);
char	**ft_split_set(const char *s, const char *charset, int *sz);
char	**ft_split_str(const char *s, t_delims arr, int *sz);
char	**ft_split_skip_delim(const char *str, t_delims delim_arr,
			char ex, int *sz);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_is_in(const char c, const char *s);
int		ft_is_delim(const char *s, t_delim *delims, int count,
			size_t *match_len);
char	*ft_empty_string(void);
void	*ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_free_delims_arr(t_delims *arr);
void	ft_free_delim_s(t_delims *arr);
int		check_edges(char **res, int *cwi);
int		count_words_skip_delim(const char *pp, t_delims arr, const char ex);
#endif
