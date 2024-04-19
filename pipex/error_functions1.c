/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:56:10 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/19 09:00:36 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_functions.h"

void	err_msg(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	output_error(TRUE, errno, format, args);
	va_end(args);
}

void	err_exit(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	output_error(TRUE, errno, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}

void	fatal(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	output_error(FALSE, 0, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}

void	usage_err(const char *format, ...)
{
	va_list args;

	ft_dprintf(STDERR_FILENO, "Usage: ");
	va_start(args, format);
	ft_vdprintf(STDERR_FILENO, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}

void	cmd_line_error(const char *format, ...)
{
	va_list args;

	ft_dprintf(STDERR_FILENO, "Command-line usage error: ");
	va_start(args, format);
	ft_vdprintf(STDERR_FILENO, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}
