/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/11 20:49:26 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_d(int d, size_t *printbyte)
{
	int		d_cpy;
	char	d_str[20];
	int		i;
	int		len;

	d_cpy = d;
	len = 0;
	i = 19;
	while (1)
	{
		if (d >= 0)
			d_str[i--] = "0123456789"[d_cpy % 10];
		else
			d_str[i--] = "0123456789"[-(d_cpy % 10)];
		d_cpy /= 10;
		len++;
		if (0 == d_cpy)
			break ;
	}
	if (d < 0)
		ft_print_d_add_minus(d_str, &i, &len);
	*printbyte += len;
	return (write(1, &d_str[++i], len));
}

void	ft_print_d_add_minus(char *d_str, int *i, int *len)
{
	d_str[(*i)--] = '-';
	(*len)++;
}

int	ft_print_u(unsigned int u, size_t *printbyte)
{
	char		u_str[19];
	int			i;
	int			len;

	len = 0;
	i = 18;
	while (1)
	{
		u_str[i--] = "0123456789"[u % 10];
		u /= 10;
		len++;
		if (0 == u)
			break ;
	}
	*printbyte += len;
	return (write(1, &u_str[++i], len));
}
