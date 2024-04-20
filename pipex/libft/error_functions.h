/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:53 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/20 23:00:51 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_FUNCTIONS_H
# define ERROR_FUNCTIONS_H

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

void	output_error(t_bool use_err, int err, const char *format, va_list args);
void	err_msg(const char *format, ...);
void	err_exit(const char *format, ...);
void	fatal(const char *format, ...);
void	usage_err(const char *format, ...);
void	cmd_line_error(const char *format, ...);

#endif
