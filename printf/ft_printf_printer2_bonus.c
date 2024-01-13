/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/13 21:59:43 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	make_str_d(t_format *spec, int d)
{
	char	d_str[19];
	int		i;

	if (d < 0)
		spec->sign = -1;
	i = 18;
	while (1)
	{
		if (-1 == spec->sign)
			d_str[i] = "0123456789"[-(d % 10)];
		else
			d_str[i] = "0123456789"[d % 10];
		d /= 10;
		(spec->str_len)++;
		if (0 == d)
			break ;
		i--;
	}
	spec->str = &d_str[i];
	return (make_str_d_spec(spec, d));
}

int	make_str_d_spec(t_format *spec)
{
	char	*str;
	int		i;

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
		
	}
}
char	*make_str_malloc(t_format *spec)
{
	spec->obj_size = spec->str_len;
	if (spec->str_len < spec->precision)
		spec->obj_size = spec->precision;
	if (-1 == spec->sign || flag_is_on(spec, FLAG_PLUS) || flag_is_on(spec, FLAG_BLANK))
		(spec->obj_size)++;
	if (spec->obj_size < spec->width)
		spec->obj_size = spec->width;
	return ((char *)malloc(sizeof(char) * spec->str_len));
}

void	make_str_sign(t_format *spec, char *str, int *i)
{
	if (-1 == spec->sign)
		str[(*i)++] = '-';
	else if (flag_is_on(spec, FLAG_PLUS))
		str[(*i)++] = '+';
	else if (flag_is_on(spec, FLAG_BLANK))
		str[(*i)++] = ' ';
}

void	make_str_precision(t_format *spec, char *str, int *i)
{
	int	j;

	j = 0;
	while (j++ < spec->precision - spec->str_len)
		str[(*i)++] = '0';
}

void	make_str_width(t_format *spec, char *str, int *i)
{
	int	j;

	j = 0;
	while (j++ < spec->width - spec->str_precision)
		str[(*i)++] = ' ';
}

int	make_str_u(t_format *spec, unsigned int u)
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
	return (write(1, &u_str[++i], len));
}
