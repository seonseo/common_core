/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_str_num_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:29:38 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/14 21:34:47 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	make_str_p_num(t_format *spec, unsigned long long p_llu, char *str_p_num)
{
	int	i;

	i = 15;
	while (1)
	{
		p_str[i--] = "0123456789abcdef"[p_llu % 16];
		p_llu /= 16;
		(spec->str_len)++;
		if (0 == p_llu)
			break ;
	}
}

void	make_str_d_num(t_format *spec, int d, char *str_d_num)
{
	int		i;

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
}

void	make_str_u_num(t_format *spec, unsigned int u, char *str_u_num)
{
	int	i;

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
}

void	make_str_x_num(t_format *spec, unsigned int u, char *base, char *str_x_num)
{
	int	i;

	i = 9;
	while (1)
	{
		str_x_num[i] = base[u % 10];
		u /= 10;
		(spec->str_len)++;
		if (0 == u)
			break ;
		i--;
	}
	spec->str = &str_x_num[i];
}
