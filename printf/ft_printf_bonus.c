/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:00 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/13 13:33:14 by seonseo          ###   ########.fr       */
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
			error = ft_print_format_string(format, args, &i, &printbyte);
		else
			error = ft_print_plain_string(format, &i, &printbyte);
	}
	va_end(args);
	if (-1 == error)
		return (-1);
	return (printbyte);
}

static int	ft_printf_format_string(const char *format, va_list args, size_t *i, size_t *printbyte)
{
	t_format	spec;//format specification
	int			error;//error flag

	(*i)++;
	spec = (t_format){};
	spec.precision = -1;
	error = 0;
	ft_read_flags(format, i, &spec);
	error = ft_read_width(format, i, &spec);
	if (-1 != error)
		error = ft_read_precision(format, i, &spec);
	if (-1 != error)
		error = ft_read_type(format, i, &spec);
	if (-1 != error)
		error = ft_is_spec_valid(&spec);
	if (-1 != error)
		error = ft_make_str(&spec, args);
	if (-1 != error)
		error = ft_print_str(&spec, printbyte);
	return (error);
}

void	ft_read_flags(const char *format, t_format *spec, size_t *i)
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

int	ft_read_width(const char *format, t_format *spec, size_t *i)
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

int	ft_read_precision(const char *format, t_format *spec, size_t *i)
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

int	ft_read_type(const char *format, t_format *spec, size_t *i)
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

int	ft_is_spec_valid(t_format *spec)
{
	if (FLAG_PLUS == spec->flags & FLAG_PLUS || \
	FLAG_BLANK == spec->flags & FLAG_BLANK)//if FLAG_PLUS or FLAG_BLANK is true
		if ('d' != spec->type && 'i' != spec->type)
			return (-1);
	if (FLAG_SHARP == spec->flags & FLAG_SHARP)
		if ('x' != spec->type && 'X' != spec->type)
			return (-1);
	if (FLAG_ZERO == spec->flags & FLAG_ZERO)
		if ('c' == spec->type || 's' == spec->type || 'p' == spec->type)
			return (-1);
	if (-1 != spec->precision)//if precision has a value
		if ('c' == spec->type || 'p' == spec->type)
			return (-1);
}

int	ft_make_str(t_format *spec, va_list args)
{
	char	type;
	int		error;

	type = spec->type;
	error = 0;
	if ('c' == type)
		error = ft_print_c(spec, va_arg(args, int));
	else if ('s' == type)
		error = ft_print_s(spec, va_arg(args, char *));
	else if ('p' == type)
		error = ft_print_p(spec, va_arg(args, void *));
	else if ('d' == type || 'i' == type)
		error = ft_print_d(spec, va_arg(args, int));
	else if ('u' == type)
		error = ft_print_u(spec, va_arg(args, unsigned int));
	else if ('x' == type)
		error = ft_print_x(spec, va_arg(args, unsigned int), "0123456789abcdef");
	else if ('X' == type)
		error = ft_print_x(spec, va_arg(args, unsigned int), "0123456789ABCDEF");
	else if ('%' == type)
		error = ft_print_c(spec, '%');
	return (error);	
}

static int	ft_print_plain_string(const char *format, size_t *i, size_t *printbyte)
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
