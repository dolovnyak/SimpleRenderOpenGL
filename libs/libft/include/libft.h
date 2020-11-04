/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:43:16 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:20:52 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_vector
{
	void			*elems_data;
	size_t			elem_size;
	size_t			size;
}					t_vector;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprintable(int ch);
int					ft_isspace(int c);
int					ft_toupper(int ch);
int					ft_tolower(int ch);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				**ft_dpclear(char **arr);
void				ft_dpclearnum(char **arr, int size);

char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int str_base);
char				*ft_ltoa_base(long nb, int base);
char				*ft_utoa_base(unsigned long nb, int base);
size_t				ft_numlen(int num);

int					ft_printf(const char *str, ...);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_multi_files_read_line(const int fd, char **line);
int					ft_single_file_read_line(const int fd, char **line);
int					ft_read_file(const char *filename, char **out_data);

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, unsigned long n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, unsigned long n);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strwnumber(const char *s);
size_t				ft_strwcnumber(const char *s, int c);
size_t				ft_strwlen(const char *s);
size_t				ft_strwclen(const char *s, int c);
size_t				ft_strchnum(const char *s, int c);
int					ft_strisnum(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
char				*ft_strjoinfree(char *s, char const *s1);
size_t				ft_strchrpos(char *s, int c);
char				*ft_strsubfree(char *s, int start, int len);
char				*ft_strnewsetchar(size_t size, char c);

void				ft_swap(int *a, int *b);
void				ft_dswap(double *a, double *b);
void				ft_fswap(float *a, float *b);

void				ft_exit_with_error(const char **error_strs, int error_code);
int					ft_log_error(const char *error, int id);

t_vector			ft_vector_create(size_t	elem_size);
void				ft_vector_free(t_vector *vector);
int					ft_vector_push_back(t_vector *vector, void *elem_data);

#endif
