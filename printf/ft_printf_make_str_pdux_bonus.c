/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_str_pdux_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/15 19:43:29 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_make_str_p(t_format *spec, void *p)
{
	unsigned long long	p_llu;
	char				str_p_num[16];
	int					i;

	p_llu = (unsigned long long)p;
	i = 15;
	while (1)
	{
		str_p_num[i] = "0123456789abcdef"[p_llu % 16];
		p_llu /= 16;
		(spec->str_len)++;
		if (0 == p_llu)
			break ;
		i--;
	}
	spec->str = &str_p_num[i];
	return (ft_printf_make_str_spec(spec));
}

int	ft_printf_make_str_d(t_format *spec, int d)
{
	char	str_d_num[10];
	int		i;

	if (d < 0)
		spec->sign = -1;
	i = 9;
	while (1)
	{
		if (-1 == spec->sign)
			str_d_num[i] = "0123456789"[-(d % 10)];
		else
			str_d_num[i] = "0123456789"[d % 10];
		d /= 10;
		(spec->str_len)++;
		if (0 == d)
			break ;
		i--;
	}
	spec->str = &str_d_num[i];
	return (ft_printf_make_str_spec(spec));
}

int	ft_printf_make_str_u(t_format *spec, unsigned int u)
{
	char	str_u_num[10];
	int		i;

	i = 9;
	while (1)
	{
		str_u_num[i] = "0123456789"[u % 10];
		u /= 10;
		(spec->str_len)++;
		if (0 == u)
			break ;
		i--;
	}
	spec->str = &str_u_num[i];
	return (ft_printf_make_str_spec(spec));
}

int	ft_printf_make_str_x(t_format *spec, unsigned int u, char *base)
{
	char	str_x_num[8];
	int		i;

	i = 7;
	while (1)
	{
		str_x_num[i] = base[u % 16];
		u /= 16;
		(spec->str_len)++;
		if (0 == u)
			break ;
		i--;
	}
	spec->str = &str_x_num[i];
	return (ft_printf_make_str_spec(spec));
}

