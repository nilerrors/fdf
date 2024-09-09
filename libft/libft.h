/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:52:10 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 20:14:35 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define TOTAL_FD 4096
# define FD_STDIN 0
# define FD_STDOUT 1
# define FD_STDERR 2

typedef bool			t_bool;
# define TRUE	1
# define FALSE	0

typedef void			*t_data;
typedef void			*t_ptr;
typedef unsigned char	t_byte;
typedef int32_t			t_int;
typedef uint32_t		t_uint;
typedef unsigned long	t_ulong;
typedef long long		t_llong;
typedef t_byte			*t_bytes;
typedef char			*t_str;
typedef int				**t_inttab;
typedef int				t_fd;

typedef struct s_list
{
	t_data			content;
	struct s_list	*next;
}	t_list;

typedef struct s_vector
{
	size_t	size;
	size_t	capacity;
	int		*items;
}	t_vector;

typedef struct s_matrix
{
	size_t		row;
	size_t		col;
	t_vector	*vec;
}	t_matrix;

// return
t_bool		ft_retf(t_str s);
t_bool		ft_rett(t_str s);

// memory allocation and manipulation
void		ft_bzero(t_data s, size_t n);
t_data		ft_calloc(size_t count, size_t size);
t_data		ft_memccpy(t_data dst, const t_data src, int c, size_t n);
t_data		ft_memchr(const t_data s, int c, size_t n);
int			ft_memcmp(const t_data s1, const t_data s2, size_t n);
t_data		ft_memcpy(t_data dst, const t_data src, size_t n);
t_data		ft_memmove(t_data dst, const t_data src, size_t len);
t_data		ft_memset(t_data b, int c, size_t len);
t_bool		ft_set_free(t_data *ptr);
t_data		ft_make_free(t_data *ptr);
t_bool		ft_free_tab(t_data *tab);

// char classification and conversion
t_bool		ft_isalnum(int c);
t_bool		ft_isalpha(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isdigit(int c);
t_bool		ft_isprint(int c);
t_bool		ft_isspace(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
t_bool		ft_char_in_str(char c, const t_str str);

// string manipulation
int			ft_atoi(const t_str str);
int			ft_htoi(const t_str str);
t_bool		ft_isinteger(const t_str str, int *n);
t_int		extract_decimal_part(float num);
t_str		ft_itoa(int n);
t_str		ft_ftoa(float n);
t_str		*ft_split(const t_str s, char c);
t_str		ft_strchr(const t_str s, int c);
t_str		ft_strdup(const t_str s1);
t_str		ft_strjoin(const t_str s1, const t_str s2);
t_str		ft_strjoin_free(const t_str s1, const t_str s2);
size_t		ft_strlcat(t_str dst, const t_str src, size_t size);
size_t		ft_strlcpy(t_str dst, const t_str src, size_t size);
size_t		ft_strlen(const t_str s);
void		ft_striteri(t_str s, void (*f)(t_uint, t_str));
t_str		ft_strmapi(const t_str s, char (*f)(t_uint, char));
t_int		ft_strncmp(const t_str s1, const t_str s2, size_t n);
t_str		ft_strnstr(const t_str haystack, const t_str needle, size_t len);
t_str		ft_strrchr(const t_str s, int c);
t_str		ft_strtrim(const t_str s1, const t_str set);
t_str		ft_substr(const t_str s, t_uint start, size_t len);
t_str		ft_extract_line(const t_str from);
t_str		ft_extract_line_no_endl(const t_str from);
t_bool		ft_strstartswith(t_str s, t_str start);
t_bool		ft_strendswith(t_str s, t_str end);

// list -> linked list
t_list		*ft_lstnew(t_data content);
void		ft_lstadd_front(t_list **lst, t_list *new_elem);
size_t		ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_elem);
void		ft_lstremove(t_list **lst, t_list *node, void (*del)(t_data));
void		ft_lstdelone(t_list *lst, void (*del)(t_data));
void		ft_lstclear(t_list **lst, void (*del)(t_data));
void		ft_lstiter(t_list *lst, void (*f)(t_data));
t_list		*ft_lstmap(t_list *lst, t_data (*f)(t_data), void (*del)(t_data));

// vector -> dynamic array
t_vector	*vector_create(size_t capacity);
t_bool		vector_clear(t_vector *list);
t_bool		vector_destroy(t_vector *list);
t_bool		vector_isempty(t_vector *list);
t_bool		vector_set(t_vector *list, size_t index, int new_item);
t_bool		vector_get(t_vector *list, size_t index, int *item);
t_bool		vector_find(t_vector *list, int item, size_t *index);
t_bool		vector_del(t_vector *list, size_t index);
t_bool		vector_double_capacity(t_vector *list);
t_bool		vector_add(t_vector *list, int new_item);
t_bool		vector_insert(t_vector *list, size_t index, int new_item);
t_bool		vector_find_smallest(t_vector *list, size_t *index);
t_bool		vector_mean(t_vector *list, long *mean);
int			vector_cost_move_to_top(size_t size, size_t index);

// matrix
t_matrix	*matrix_create(t_uint rows, t_uint cols);
t_bool		matrix_destroy(t_matrix *mat);
t_int		matrix_get(t_matrix *m, t_uint x, t_uint y);
t_bool		matrix_set(t_matrix *m, t_uint x, t_uint y, t_int val);

// io
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(t_str s, int fd);
void		ft_putendl(t_str s);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(t_str s, int fd);
int			ft_printf(const t_str s, ...);
int			ft_printerr(const t_str s, ...);
int			ft_printfd(t_fd fd, const t_str s, ...);
size_t		ft_puts(t_fd fd, const t_str s);
size_t		ft_putc(t_fd fd, int c);
size_t		ft_putd(t_fd fd, int d);
size_t		ft_putf(t_fd fd, float nbr);
size_t		ft_putp(t_fd fd, t_data addr);
size_t		ft_putu(t_fd fd, t_uint n);
size_t		ft_putx(t_fd fd, t_uint n, const char f);
t_str		get_next_line(int fd);
t_str		get_next_line_with_abort(int fd, t_bool abort);

#endif // LIBFT_H
