/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_str_pdux_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/14 21:44:18 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	make_str_p(t_format *spec, void *p)
{
	unsigned long long	p_llu;
	char				str_p_num[16];
	char				*str;
	int					flag_minus;
	size_t				i;

	p_llu = (unsigned long long)p;
	flag_minus = flag_is_on(spec, FLAG_MINUS);
	make_str_p_num(spec, p_llu, str_p_num);
	str = make_str_malloc(spec);
	if (NULL == str)
		return (-1);
	i = 0;
	if (!flag_minus)
		make_str_width(spec, str, &i);
	make_str_prefix(spec, str, &i);
	make_str_precision(spec, str, &i);
	make_str_cpy_num(spec, str, &i);
	if (flag_minus)
		make_str_width(spec, str, &i);
	spec->str = str;
	return (0);
}

int	make_str_d(t_format *spec, int d)
{
	char	str_d_num[10];
	char	*str;
	int		flag_minus;
	size_t	i;

	if (d < 0)
		spec->sign = -1;
	flag_minus = flag_is_on(spec, FLAG_MINUS);
	make_str_d_num(spec, d, str_d_num);
	str = make_str_malloc(spec);
	if (NULL == str)
		return (-1);
	i = 0;
	if (!flag_minus)
		make_str_width(spec, str, &i);
	make_str_prefix(spec, str, &i);
	make_str_precision(spec, str, &i);
	make_str_cpy_num(spec, str, &i);
	if (flag_minus)
		make_str_width(spec, str, &i);
	spec->str = str;
	return (0);
}

int	make_str_u(t_format *spec, unsigned int u)
{
	char	str_u_num[10];
	char	*str;
	int		flag_minus;
	size_t	i;

	flag_minus = flag_is_on(spec, FLAG_MINUS);
	make_str_u_num(spec, u, str_u_num);
	str = make_str_malloc(spec);
	if (NULL == str)
		return (-1);
	i = 0;
	if (!flag_minus)
		make_str_width(spec, str, &i);
	make_str_prefix(spec, str, &i);
	make_str_precision(spec, str, &i);
	make_str_cpy_num(spec, str, &i);
	if (flag_minus)
		make_str_width(spec, str, &i);
	spec->str = str;
	return (0);
}

int	make_str_x(t_format *spec, unsigned int u, char *base)
{
	char	str_x_num[10];
	char	*str;
	int		flag_minus;
	size_t	i;

	flag_minus = flag_is_on(spec, FLAG_MINUS);
	make_str_x_num(spec, u, base, str_x_num);
	str = make_str_malloc(spec);
	if (NULL == str)
		return (-1);
	i = 0;
	if (!flag_minus)
		make_str_width(spec, str, &i);
	make_str_prefix(spec, str, &i);
	make_str_precision(spec, str, &i);
	make_str_cpy_num(spec, str, &i);
	if (flag_minus)
		make_str_width(spec, str, &i);
	spec->str = str;
	return (0);
}

make_str_spec(tformat *spec, char *str, size_t *i)
