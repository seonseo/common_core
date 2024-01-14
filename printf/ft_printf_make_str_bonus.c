/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_str_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/14 20:31:56 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*make_str_malloc(t_format *spec)
{
	spec->obj_size = spec->str_len;
	if (spec->precision >= 0 && spec->obj_size < (size_t)spec->precision)
		spec->obj_size = spec->precision;
	if (-1 == spec->sign || flag_is_on(spec, FLAG_PLUS) || flag_is_on(spec, FLAG_BLANK))
		(spec->obj_size)++;
	spec->rest_width = spec->obj_size;
	if (spec->obj_size < (size_t)spec->width)
		spec->obj_size = spec->width;
	return ((char *)malloc(sizeof(char) * spec->obj_size));
}

void	make_str_prefix(t_format *spec, char *str, size_t *i)
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
	if (flag_is_on(spec, FLAG_SHARP))
	{
		if ('x' == spec->type)
			ft_memcpy(&str[*i], "0x", 2);
		else
			ft_memcpy(&str[*i], "0X", 2);
		(*i) += 2;
		spec->prefix += 2;
	}
}

void	make_str_precision(t_format *spec, char *str, size_t *i)
{
	int	padding;

	if (spec->precision > 0 && (size_t)spec->precision > spec->str_len)
	{
		padding = (size_t)spec->precision - spec->str_len;
		ft_memset(&str[*i], '0', padding);
		(*i) += padding;
	}
}

void	make_str_width(t_format *spec, char *str, size_t *i)
{
	int	padding;

	if (spec->obj_size > spec->rest_width)
	{
		padding = spec->obj_size - spec->rest_width;
		if (flag_is_on(spec, FLAG_ZERO) && !flag_is_on(spec, FLAG_MINUS))
			ft_memset(&str[*i], '0', padding);
		else
			ft_memset(&str[*i], ' ', padding);
		(*i) += padding;
	}
}

void	make_str_cpy_num(t_format *spec, char *str, size_t *i)
{
	ft_memcpy(&str[*i], spec->str, spec->str_len);
	(*i) += spec->str_len;
}

