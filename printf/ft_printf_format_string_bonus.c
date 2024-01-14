/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_string_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:18:51 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/14 20:21:40 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		read_spec(const char *format, t_format *spec, size_t *i)
{
	int	error;

	error = 0;
	read_flags(format, spec, i);
	error = read_width(format, spec, i);
	if (-1 != error)
		error = read_precision(format, spec, i);
	if (-1 != error)
		error = read_type(format, spec, i);
	return (error);
}

int	flag_is_on(t_format *spec, int flag)
{
	if (flag == (spec->flags & flag))
		return (1);
	return (0);
}

int	check_spec(t_format *spec)
{
	if (flag_is_on(spec, FLAG_PLUS) || flag_is_on(spec, FLAG_BLANK))
		if ('d' != spec->type && 'i' != spec->type)
			return (-1);
	if (flag_is_on(spec, FLAG_SHARP))
		if ('x' != spec->type && 'X' != spec->type)
			return (-1);
	if (flag_is_on(spec, FLAG_ZERO))
		if ('c' == spec->type || 's' == spec->type || 'p' == spec->type)
			return (-1);
	if (-1 != spec->precision)//if precision has a value
		if ('c' == spec->type || 'p' == spec->type)
			return (-1);
	return (0);
}

int	make_str(t_format *spec, va_list args)
{
	char	type;
	int		error;

	type = spec->type;
	error = 0;
	if ('c' == type)
		error = make_str_c(spec, va_arg(args, int));
	else if ('s' == type)
		error = make_str_s(spec, va_arg(args, char *));
	else if ('p' == type)
		error = make_str_p(spec, va_arg(args, void *));
	else if ('d' == type || 'i' == type)
		error = make_str_d(spec, va_arg(args, int));
	else if ('u' == type)
		error = make_str_u(spec, va_arg(args, unsigned int));
	else if ('x' == type)
		error = make_str_x(spec, va_arg(args, unsigned int), "0123456789abcdef");
	else if ('X' == type)
		error = make_str_x(spec, va_arg(args, unsigned int), "0123456789ABCDEF");
	else if ('%' == type)
		error = make_str_c(spec, '%');
	return (error);	
}

int	print_str(t_format *spec, size_t *printbyte)
{
	if (-1 == write(1, spec->str, spec->obj_size))
		return (-1);
	(*printbyte) += spec->obj_size;
	return (0);
}
