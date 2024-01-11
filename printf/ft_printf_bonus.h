/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:14:21 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/11 21:15:25 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

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
#endif
