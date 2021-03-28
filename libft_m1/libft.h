/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:57:27 by tnotch            #+#    #+#             */
/*   Updated: 2021/03/01 18:31:07 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_list
{
	void 				*content;
	struct s_list		*next;
}						t_list;


int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int ch);
int					ft_isdigit(int c);
int					ft_isprint(int ch);
char				*ft_itoa(int n);
void				*ft_memccpy(void *restrict dest, const void *restrict src, int ch, size_t count);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
void				*ft_memmove(void *destination, const void *source, size_t n);
void				*ft_memset(void *destination, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_reverse(char *str);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int ch);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
size_t  			ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
size_t				ft_strlcpy(char *restrict dst, const char *restrict src, size_t buf);
long unsigned int	ft_strlen(const char *str);
char 				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle, size_t len);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
