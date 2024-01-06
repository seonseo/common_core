/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:00 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/05 20:49:27 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	printbyte;
	int		errorflag;
	va_list	args;

	if (NULL == format)
		return (-1);
	va_start(args, format);
	errorflag = 0;
	printbyte = 0;
	i = 0;
	while (format[i] && 0 == errorflag)
	{
		if ('%' == format[i])
			errorflag = ft_print_format_string(format, args, &(++i), &printbyte);
		else
			errorflag = ft_print_plain_string(format, &i, &printbyte);
	}
	va_end(args);
	if (-1 == errorflag)
		return (-1);
	return (printbyte);
}

int	ft_print_format_string(const char *format, va_list args, size_t *i, size_t *printbyte)
{
	int	errorflag;

	errorflag = 0;
	if ('c' == format[*i])
		errorflag = ft_print_c(va_arg(args, char), printbyte);
	else if ('s' == format[*i])
		errorflag = ft_print_s(va_arg(args, char *), printbyte);
	else if ('p' == format[*i])
		errorflag = ft_print_p(va_arg(args, void *), printbyte);
	else if ('d' == format[*i])
		errorflag = ft_print_d(va_arg(args, long long), printbyte);
	else if ('i' == format[*i])
		errorflag = ft_print_i(va_arg(args, long long), printbyte);
	else if ('u' == format[*i])
		errorflag = ft_print_u(va_arg(args, unsigned long long), printbyte);
	else if ('x' == format[*i])
		errorflag = ft_print_x(va_arg(args, long long), printbyte);
	else if ('X' == format[*i])
		errorflag = ft_print_xx(va_arg(args, long long), printbyte);
	else if ('%' == format[*i])
		errorflag = ft_print_percent(printbyte);
	(*i)++;
	if (-1 == errorflag)
		return (-1);
	return (0);
}

int	ft_print_plain_string(const char *format, size_t *i, size_t *printbyte)
{
	const char	*start;
	size_t	len;

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

#include <stdio.h>

int	main(void)
{
	int	a;
	int	printbyte;

	a = 3;
	printbyte = ft_printf("nice%dxperiment\n", a);
	printf("%d\n", printbyte);
	return (0);
}