/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:14:21 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/13 00:54:43 by seonseo          ###   ########.fr       */
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
	char		flags;
	size_t		width;
	long long	precision;
	char		type;
	char		*str;
	size_t		str_len;
	size_t		mem_size;
}	t_format;

int		ft_printf(const char *format, ...);
int		ft_print_format_string(const char *format, \
va_list args, size_t *i, size_t *printbyte);
int		ft_print_plain_string(const char *format, size_t *i, size_t *printbyte);
size_t	ft_printf_strlen(const char *s);

int		ft_print_c(char c, size_t *printbyte);
int		ft_print_s(char *s, size_t *printbyte);
int		ft_print_p(void *p, size_t *printbyte);
int		ft_print_x(unsigned int u, char *base, size_t *printbyte);
int		ft_print_d(int d, size_t *printbyte);
void	ft_print_d_add_minus(char *lld_str, int	*i, int *len);
int		ft_print_u(unsigned int u, size_t *printbyte);

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
#endif
