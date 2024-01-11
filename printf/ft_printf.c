/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:00 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/11 21:20:41 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	printbyte;
	int		error;
	va_list	args;

	if (NULL == format)
		return (-1);
	va_start(args, format);
	error = 0;
	printbyte = 0;
	i = 0;
	while (format[i] && -1 != error)
	{
		if ('%' == format[i])
		{
			i++;
			error = ft_print_format_string(format, args, &i, &printbyte);
		}
		else
			error = ft_print_plain_string(format, &i, &printbyte);
	}
	va_end(args);
	if (-1 == error)
		return (-1);
	return (printbyte);
}

int	ft_print_format_string(const char *format, \
va_list args, size_t *i, size_t *printbyte)
{
	int	error;

	error = 0;
	if ('c' == format[*i])
		error = ft_print_c(va_arg(args, int), printbyte);
	else if ('s' == format[*i])
		error = ft_print_s(va_arg(args, char *), printbyte);
	else if ('p' == format[*i])
		error = ft_print_p(va_arg(args, void *), printbyte);
	else if ('d' == format[*i] || 'i' == format[*i])
		error = ft_print_d(va_arg(args, int), printbyte);
	else if ('u' == format[*i])
		error = ft_print_u(va_arg(args, unsigned int), printbyte);
	else if ('x' == format[*i])
		error = ft_print_x(va_arg(args, unsigned int), \
		"0123456789abcdef", printbyte);
	else if ('X' == format[*i])
		error = ft_print_x(va_arg(args, unsigned int), \
		"0123456789ABCDEF", printbyte);
	else if ('%' == format[*i])
		error = ft_print_c('%', printbyte);
	(*i)++;
	return (error);
}

int	ft_print_plain_string(const char *format, size_t *i, size_t *printbyte)
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
