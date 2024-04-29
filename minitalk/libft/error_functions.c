/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:56:10 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/28 22:47:33 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_ENAME 106
#define BUF_SIZE 500

void	output_error(const char *format, va_list args)
{
	char	buf[BUF_SIZE];
	char	user_msg[BUF_SIZE];
	char	err_text[BUF_SIZE];

	ft_vsnprintf(user_msg, BUF_SIZE, format, args);
	ft_snprintf(err_text, BUF_SIZE, ":");
	ft_snprintf(buf, BUF_SIZE, "ERROR%s %s\n", err_text, user_msg);
	ft_putstr_fd(buf, 2);
}
