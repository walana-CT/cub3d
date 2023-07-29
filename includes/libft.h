/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:24:22 by rficht            #+#    #+#             */
/*   Updated: 2023/07/27 16:52:15 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

# define TRUE	1
# define FALSE	0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_strlist
{
	char				*str;
	size_t				str_len;
	struct s_strlist	*next;	
}	t_strlist;

//Math
int			ft_abs(int nbr);
int			ft_max_int(int a, int b);

//convertion functions
int			ft_atoi(const char *str);
char		*ft_itoa(long int n);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_itohex_ptr(void *nbr, int up);
char		*ft_itohex(unsigned int nbr, int up);

//chained list functions
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

//parting functions
char		*ft_get_next_line(int fd);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isnumeric(int c);
int			ft_isprint(int c);

//memory
void		*ft_calloc(size_t count, size_t size);

//writting functions
int			ft_printf(const char *format, ...);
void		ft_bzero(void *s, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

//string manipulation
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset( void *b, int c, size_t count);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//string list functionsß`
void		ft_strlst_addback(t_strlist **strlst, t_strlist *strlst_new);
void		ft_strlst_del(t_strlist *lst);
int			ft_strlst_clear(t_strlist **lst);
t_strlist	*ft_strlst_new(char *str, size_t str_len);
int			ft_strlst_len(t_strlist *lst);
char		*ft_strlst_merge(t_strlist *lst, int str_len);

# ifndef HEX_BASE_LOW
#  define HEX_BASE_LOW "0123456789abcdef"
# endif

# ifndef HEX_BASE_UP
#  define HEX_BASE_UP "0123456789ABCDEF"
# endif

# ifndef HEX_BASE_LST
#  define HEX_BASE_LST "0123456789ABCDEFabcdefx"
# endif

#endif