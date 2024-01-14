/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/14 16:29:35 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	make_str_c(t_format *spec, char c)
{
	*spec = (t_format){};
	return (write(1, &c, 1));
}

int	make_str_s(t_format *spec, char *s)
{
	*spec = (t_format){};
	if (NULL == s)
		return (write(1, "(null)", 6));
	spec->str_len = ft_strlen(s);
	return (write(1, s, spec->str_len));
}

int	make_str_u(t_format *spec, unsigned int u)
{
	char		u_str[19];
	int			i;

	spec->str_len = 0;
	i = 18;
	while (1)
	{
		u_str[i--] = "0123456789"[u % 10];
		u /= 10;
		spec->str_len++;
		if (0 == u)
			break ;
	}
	return (write(1, &u_str[++i], spec->str_len));
}

int	make_str_p(t_format *spec, void *p)
{
	unsigned long long	p_llu;
	char				p_str[18];
	int					i;

	p_llu = (unsigned long long)p;
	spec->str_len = 2;
	i = 17;
	while (1)
	{
		p_str[i--] = "0123456789abcdef"[p_llu % 16];
		p_llu /= 16;
		(spec->str_len)++;
		if (0 == p_llu)
			break ;
	}
	p_str[i--] = 'x';
	p_str[i--] = '0';
	return (write(1, &p_str[++i], spec->str_len));
}

int	make_str_x(t_format *spec, unsigned int u, char *base)
{
	char				u_str[18];
	int					i;

	i = 17;
	while (1)
	{
		u_str[i--] = base[u % 16];
		u /= 16;
		(spec->str_len)++;
		if (0 == u)
			break ;
	}
	return (write(1, &u_str[++i], spec->str_len));
}
