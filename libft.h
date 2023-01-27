/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:47:10 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/18 12:47:15 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define DECIMAL "0123456789"
# define HEX "0123456789abcdef"
# define HEXMAY "0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
char			*ft_strdup(char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				ft_printf(char const *printf, ...);
int				do_number(int n);
int				do_string(char *cad);
int				do_char(int cha);
int				do_percent(void);
int				do_pointer_pre(unsigned long n, char *ER, int base);
int				do_pointer(unsigned long n, char *ER, int base);
void			free_content_lstclear(void *string);
int				ft_strcmp(char *s1, char *s2);
void			ft_split_clear(char **split, void (*del)(void*));
char			*get_next_line(int fd);
#endif 
