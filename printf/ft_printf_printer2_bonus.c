/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/14 17:25:29 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	make_str_d(t_format *spec, int d)
{
	char	str_d_num[19];
	char	*str;
	int		i;

	if (d < 0)
		spec->sign = -1;
	make_str_d_num(spec, d, str_d_num);
	str = make_str_malloc(spec);
	if (NULL == str)
		return (-1);
	i = 0;
	if (flag_is_on(spec, FLAG_MINUS))
	{
		make_str_sign(spec, str, &i);
		make_str_precision(spec, str, &i);
		make_str_width(spec, str, &i);
	}
	else
	{
		make_str_width(spec, str, &i);
		make_str_sign(spec, str, &i);
		make_str_precision(spec, str, &i);
	}
	spec->str = str;
	return (0);
}

void	make_str_d_num(t_format *spec, int d, char *str_d_num)
{
	int		i;

	i = 18;
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

char	*make_str_malloc(t_format *spec)
{
	spec->obj_size = spec->str_len;
	if (spec->precision >= 0 && spec->obj_size < (size_t)spec->precision)
		spec->obj_size = spec->precision;
	if (-1 == spec->sign || flag_is_on(spec, FLAG_PLUS) || flag_is_on(spec, FLAG_BLANK))
		(spec->obj_size)++;
	if (spec->obj_size < spec->width)
		spec->obj_size = spec->width;
	return ((char *)malloc(sizeof(char) * spec->obj_size));
}

void	make_str_sign(t_format *spec, char *str, int *i)
{
	(spec->prefix)++;
	if (-1 == spec->sign)
		str[(*i)++] = '-';
	else if (flag_is_on(spec, FLAG_PLUS))
		str[(*i)++] = '+';
	else if (flag_is_on(spec, FLAG_BLANK))
		str[(*i)++] = ' ';
	else
		(spec->prefix)--;
}

void	make_str_precision(t_format *spec, char *str, int *i)
{
	int	j;

	j = 0;
	while (spec->precision >= 0 && j++ < spec->precision - spec->str_len)
		str[(*i)++] = '0';
}

void	make_str_width(t_format *spec, char *str, int *i)
{
	int	j;
	int	repeat;

	if (spec->precision > 0 )
		repeat = spec->width - spec->precision - spec->prefix;
	else
		repeat = spec->width - spec->prefix;
	j = 0;
	while (j++ < repeat)
	{
		if (flag_is_on(spec, FLAG_ZERO))
			str[(*i)++] = '0';
		else
			str[(*i)++] = ' ';
	}
}

