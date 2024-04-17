/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:31:35 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/23 21:26:45 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(char *err_msg, int perror_flag)
{
	if (!perror_flag)
		ft_putendl_fd(err_msg, 2);
	else
		perror(err_msg);
	exit(1);
}

int	exit_no_error(void)
{
	exit(0);
}
