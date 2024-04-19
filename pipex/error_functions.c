/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:56:10 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/19 09:09:18 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_functions.h"

#define BUF_SIZE 500

void	output_error(t_bool use_err, int err, const char *format, va_list args)
{
	char	buf[BUF_SIZE];
	char	user_msg[BUF_SIZE];
	char	err_text[BUF_SIZE];
	char	*error_name;

	ft_vsnprintf(user_msg, BUF_SIZE, format, args);

	if (use_err)
	{
		if (0 < err && err <= MAX_ENAME)
			error_name = ename[err];
		else
			error_name = "?UNKNOWN?";
		ft_snprintf(err_text, BUF_SIZE, " [%s %s]", error_name, strerror(err));
	}
	else
		ft_snprintf(err_text, BUF_SIZE, ":");

	ft_snprintf(buf, BUF_SIZE, "ERROR%s %s\n", err_text, user_msg);
	ft_putstr_fd(buf, 2);
}
