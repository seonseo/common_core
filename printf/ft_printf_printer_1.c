/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/06 12:17:30 by seonseo          ###   ########.fr       */
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
	char				p_str[16];
	int					i;
	int					len;

	p_llu = (unsigned long long)p;
	len = 2;
	i = 15;
	while (p_llu)
	{
		p_str[i] = "0123456789abcdef"[p_llu % 16];
		p_llu /= 16;
		len++;
		i--;
	}
	write(1, "0x", 2);
	write(1, p_str)
}

int		ft_print_d(long long n, size_t *printbyte)
{
	
}

int		ft_print_i(long long n, size_t *printbyte)
{

}
