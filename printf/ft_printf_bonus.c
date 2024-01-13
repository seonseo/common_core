/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:00 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/13 21:38:19 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	printbyte;
	int		error;
	va_list	args;

	va_start(args, format);
	error = 0;
	printbyte = 0;
	i = 0;
	while (format[i] && -1 != error)
	{
		if ('%' == format[i])
			error = print_format_string(format, args, &i, &printbyte);
		else
			error = print_plain_string(format, &i, &printbyte);
	}
	va_end(args);
	if (-1 == error)
		return (-1);
	return (printbyte);
}

static int	print_format_string(const char *format, va_list args, size_t *i, size_t *printbyte)
{
	t_format	spec;//format specification
	int			error;//error flag

	(*i)++;
	spec = (t_format){};
	spec.precision = -1;
	error = 0;
	read_flags(format, i, &spec);
	error = read_width(format, i, &spec);
	if (-1 != error)
		error = read_precision(format, i, &spec);
	if (-1 != error)
		error = read_type(format, i, &spec);
	if (-1 != error)
		error = is_spec_valid(&spec);
	if (-1 != error)
		error = make_str(&spec, args);
	if (-1 != error)
		error = print_str(&spec, printbyte);
	return (error);
}

void	read_flags(const char *format, t_format *spec, size_t *i)
{
	while (1)
	{
		if ('-' == format[*i])
			spec->flags |= FLAG_MINUS;
		else if ('+' == format[*i])
			spec->flags |= FLAG_PLUS;
		else if (' ' == format[*i])
			spec->flags |= FLAG_BLANK;
		else if ('#' == format[*i])
			spec->flags |= FLAG_SHARP;
		else if ('0' == format[*i])
			spec->flags |= FLAG_ZERO;
		else
			break;
		(*i)++;
	}
}

int	read_width(const char *format, t_format *spec, size_t *i)
{
	while (ft_isdigit(format[*i]))
	{
		spec->width = spec->width * 10 + format[*i] - '0';
		if (spec->width > 2147483647)
			return (-1);
		(*i)++;
	}
	return (0);
}

int	read_precision(const char *format, t_format *spec, size_t *i)
{
	if ('.' == format[*i])
	{
		(*i)++;
		if (ft_isdigit(format[*i]))
			spec->precision = 0;
		while (ft_isdigit(format[*i]))
		{
			spec->precision = spec->precision * 10 + format[*i] - '0';
			if (spec->precision > 2147483647)
				return (-1);
			(*i)++;
		}
	}
	return (0);
}

int	read_type(const char *format, t_format *spec, size_t *i)
{
	int	j;

	j = 0;
	while ("cspdiuxX%"[j] && ("cspdiuxX%"[j] != format[*i]))
		j++;
	if ('\0' == "cspdiuxX%"[j])
		return (-1);
	spec->type = format[*i];
	(*i)++;
	return (0);
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

static int	print_plain_string(const char *format, size_t *i, size_t *printbyte)
{
	const char	*start;
	size_t		len;

	start = &format[*i];
	len = ft_printf_strlen(start);
	if (write(1, start, len) == -1)
		return (-1);
	(*i) += len;
	(*printbyte) += len;
	return (0);
}

size_t	ft_printf_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '%')
		len++;
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	a;
// 	int	printbyte;

// 	a = 'a';
// 	printbyte = ft_printf("%X%%\n", a);
// 	printf("\npb:%d\n", printbyte);
// 	printbyte = printf("%X%%\n", a);
// 	printf("\npb:%d\n", printbyte);
// 	return (0);
// }
