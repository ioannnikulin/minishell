/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:55:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 18:59:46 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include "../../libft.h"
# include "types.h"
# include "strings_internal.h"

typedef struct s_sbuf
{
	char	*content;
	int		sz;
	int		capacity;
	int		step;
}	t_sbuf;

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
char	*ft_empty_string(void);
void	*ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_free_delims_arr(t_delims *arr);
void	ft_free_delim_s(t_delims *arr);
char	*ft_replace_idx(char **where, int fromIncl, int toExcl, char *with);

t_sbuf	*ft_sbuf_make(char *src);
t_sbuf	*ft_sbuf_realloc(t_sbuf *sbuf, int ncap);
t_sbuf	*ft_sbuf_append(t_sbuf *sbuf, char *what);
char	*ft_sbuf_get(t_sbuf *sbuf);
int		ft_sbuf_finalize(t_sbuf **sbuf);
#endif
