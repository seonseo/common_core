/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/12 17:10:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_c(char c, size_t *printbyte)
{
	(*printbyte)++;
	return (write(1, &c, 1));
}

int	ft_print_s(char *s, size_t *printbyte)
{
	size_t	len;

	if (NULL == s)
	{
		*printbyte += 6;
		return (write(1, "(null)", 6));
	}
	len = ft_strlen(s);
	*printbyte += len;
	return (write(1, s, len));
}

int	ft_print_p(void *p, size_t *printbyte)
{
	unsigned long long	p_llu;
	char				p_str[18];
	int					i;
	size_t				len;

	p_llu = (unsigned long long)p;
	len = 2;
	i = 17;
	while (1)
	{
		p_str[i--] = "0123456789abcdef"[p_llu % 16];
		p_llu /= 16;
		len++;
		if (0 == p_llu)
			break ;
	}
	p_str[i--] = 'x';
	p_str[i--] = '0';
	*printbyte += len;
	return (write(1, &p_str[++i], len));
}

int	ft_print_x(unsigned int u, char *base, size_t *printbyte)
{
	char				u_str[18];
	int					i;
	size_t				len;

	len = 0;
	i = 17;
	while (1)
	{
		u_str[i--] = base[u % 16];
		u /= 16;
		len++;
		if (0 == u)
			break ;
	}
	*printbyte += len;
	return (write(1, &u_str[++i], len));
}
