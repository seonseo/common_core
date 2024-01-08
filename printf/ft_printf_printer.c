/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/08 17:54:57 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(char c, size_t *printbyte)
{
	if (-1 == write(1, &c, 1))
		return (-1);
	(*printbyte)++;
	return (0);
}

int		ft_print_s(char *s, size_t *printbyte)
{
	size_t	len;

	len = ft_strlen(s);
	if (-1 == write(1, s, len))
		return (-1);
	*printbyte += len;
	return (0);
}

int		ft_print_p(void *p, size_t *printbyte)
{
	unsigned long long	p_llu;
	char				p_str[18];
	int					i;
	int					len;

	p_llu = (unsigned long long)p;
	len = 2;
	i = 17;
	while (1)
	{
		p_str[i--] = "0123456789abcdef"[p_llu % 16];
		p_llu /= 16;
		len++;
		if (0 == p_llu)
			break;
	}
	p_str[i--] = 'x';
	p_str[i] = '0';
	(*printbyte) += len;
	if (-1 == write(1, &p_str[i], len))
		return (-1);
	return (len);
}
#include <limits.h>

int		ft_print_d(long long n, size_t *printbyte)
{
	char	*d_str[20];
	int		sign;
	int		i;
	int		len;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = 0;
	i = 19;
	while (1)
	{
		d_str[i--] = "0123456789"[n % 10];
		n /= 10;
		len++;
		if (0 == n)
			break;
	}
	if (-1 == sign)
	{
		d_str[i--] = '-';
		len++;
	}
	if (-1 == write(1, &d_str[++i], len))
		return (-1);
	return (len);
}

int		ft_print_u(unsigned long long n, size_t *printbyte)
{

}
