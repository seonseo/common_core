/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:14:21 by macbookair        #+#    #+#             */
/*   Updated: 2024/02/13 19:01:37 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX	2147483647
# endif

# define FLAG_MINUS	0b00000001
# define FLAG_PLUS	0b00000010
# define FLAG_BLANK	0b00000100
# define FLAG_SHARP	0b00001000
# define FLAG_ZERO	0b00010000

typedef struct s_format
{
	int			flags;
	long long	width;
	long long	precision;
	char		type;
	int			sign;
	char		*str;
	size_t		str_len;
	size_t		trimmed_str_len;
	size_t		obj_size;
}	t_format;

//ft_printf.c
int		ft_printf(const char *format, ...);
int		ft_printf_print_format_string(const char *format, va_list args, \
size_t *i, size_t *printbyte);
int		ft_printf_print_plain_string(const char *format, \
size_t *i, size_t *printbyte);
size_t	ft_printf_strlen(const char *s);

//ft_printf_print_format_string.c
int		ft_printf_read_spec(const char *format, t_format *spec, size_t *i);
int		flag_is_on(int flags, int flag);
int		ft_printf_check_spec(t_format *spec);
int		ft_printf_make_str(t_format *spec, va_list args);
int		ft_printf_print_str(t_format *spec, size_t *printbyte);

//ft_printf_read_spec.c
void	ft_printf_read_flags(const char *format, t_format *spec, size_t *i);
int		ft_printf_read_width(const char *format, t_format *spec, size_t *i);
int		ft_printf_read_precision(const char *format, t_format *spec, size_t *i);
int		ft_printf_read_type(const char *format, t_format *spec, size_t *i);

//ft_printf_make_str_cs.c
int		ft_printf_make_str_c(t_format *spec, char c);
int		ft_printf_make_str_s(t_format *spec, char *s);

//ft_printf_make_str_pdux.c
int		ft_printf_make_str_p(t_format *spec, void *p);
int		ft_printf_make_str_d(t_format *spec, int d);
int		ft_printf_make_str_u(t_format *spec, unsigned int u);
int		ft_printf_make_str_x(t_format *spec, unsigned int u, char *base);

//ft_printf_make_str_spec1.c
int		ft_printf_make_str_spec(t_format *spec);

//ft_printf_make_str_spec2.c
char	*ft_printf_make_str_malloc(t_format *spec);
void	ft_printf_make_str_prefix(t_format *spec, char *str, size_t *i);
void	ft_printf_make_str_precision(t_format *spec, char *str, size_t *i);
void	ft_printf_make_str_width(t_format *spec, char *str, size_t *i);
void	ft_printf_make_str_cpy_num(t_format *spec, char *str, size_t *i);

//libft.a
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
