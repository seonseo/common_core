/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:14:21 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/14 17:24:48 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FLAG_MINUS	0b00000001
# define FLAG_PLUS	0b00000010
# define FLAG_BLANK	0b00000100
# define FLAG_SHARP	0b00001000
# define FLAG_ZERO	0b00010000

typedef struct s_format
{
	int			flags;
	int			width;
	long long	precision;
	int			prefix;
	char		type;
	int			sign;
	char		*str;
	size_t		str_len;
	size_t		obj_size;
}	t_format;

int		ft_printf(const char *format, ...);
int		print_format_string(const char *format, va_list args, size_t *i, size_t *printbyte);
int		print_plain_string(const char *format, size_t *i, size_t *printbyte);
size_t	ft_printf_strlen(const char *s);

int		read_spec(const char *format, t_format *spec, size_t *i);
int		check_spec(t_format *spec);
int		make_str(t_format *spec, va_list args);
int		print_str(t_format *spec, size_t *printbyte);

int		flag_is_on(t_format *spec, int flag);

void	read_flags(const char *format, t_format *spec, size_t *i);
int		read_width(const char *format, t_format *spec, size_t *i);
int		read_precision(const char *format, t_format *spec, size_t *i);
int		read_type(const char *format, t_format *spec, size_t *i);

int		make_str_c(t_format *spec, char c);
int		make_str_s(t_format *spec, char *s);
int		make_str_p(t_format *spec, void *p);
int		make_str_x(t_format *spec, unsigned int u, char *base);
int		make_str_d(t_format *spec, int d);
int		make_str_u(t_format *spec, unsigned int u);

void	make_str_d_num(t_format *spec, int d, char *str_d_num);

char	*make_str_malloc(t_format *spec);
void	make_str_sign(t_format *spec, char *str, int *i);
void	make_str_precision(t_format *spec, char *str, int *i);
void	make_str_width(t_format *spec, char *str, int *i);

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);

#endif
