/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:31:35 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/14 15:28:34 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(char *err_msg, int perror_flag)
{
	if (!perror_flag)
		ft_putendl_fd(err_msg, 2);
	else
		perror(err_msg);
	exit(1);
}
