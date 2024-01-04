/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:13:00 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/04 22:16:24 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	printbyte;
	va_list	args;
	int		errorflag;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	errorflag = 0;
	printbyte = 0;
	i = 0;
	while (format[i] && 0 == errorflag)
	{
		if (format[i] == '%')
			errorflag = ft_print_format_string(format, args, &i, &printbyte);
		else
			errorflag = ft_print_plain_string(format, &i, &printbyte);
	}
	va_end(args);
	if (-1 == errorflag)
		printbyte = -1;
	return (printbyte);
}

int	ft_print_format_string(const char *format, va_list args, &i, &printbyte)
{
	
}

int	ft_print_plain_string(const char *format, &i, &printbyte)
{
	char    *
}
