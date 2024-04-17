/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:05:12 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/23 19:34:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook_zoom(int keycode, t_vars *vars)
{
	if (PLUS_KEY == keycode)
		zoom_in(&vars->matrix);
	else if (MINUS_KEY == keycode)
		zoom_out(&vars->matrix);
}

void	zoom_in(t_matrix *matrix)
{
	int		i;
	int		j;
	int		m;
	int		n;

	m = 21;
	n = 1;
	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			matrix->data[i][j].x = \
			((m * matrix->data[i][j].x) - (n * matrix->center.x)) / (m - n);
			matrix->data[i][j].y = \
			((m * matrix->data[i][j].y) - (n * matrix->center.y)) / (m - n);
			matrix->data[i][j].z = \
			((m * matrix->data[i][j].z) - (n * matrix->center.z)) / (m - n);
			j++;
		}
		i++;
	}
}

void	zoom_out(t_matrix *matrix)
{
	int		i;
	int		j;
	int		m;
	int		n;

	m = 20;
	n = 1;
	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			matrix->data[i][j].x = \
			((m * matrix->data[i][j].x) + (n * matrix->center.x)) / (m + n);
			matrix->data[i][j].y = \
			((m * matrix->data[i][j].y) + (n * matrix->center.y)) / (m + n);
			matrix->data[i][j].z = \
			((m * matrix->data[i][j].z) + (n * matrix->center.z)) / (m + n);
			j++;
		}
		i++;
	}
}
