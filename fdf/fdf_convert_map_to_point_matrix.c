/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_convert_map_to_point_matrix.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:06:53 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/23 20:55:26 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_map_to_point_matrix(t_vars *vars, int interval)
{
	init_matrix_member(vars, interval);
	malloc_point_matrix(&vars->matrix);
	get_matrix_start_point(vars);
	fill_matrix_as_map(vars, interval);
}

void	init_matrix_member(t_vars *vars, int interval)
{
	vars->matrix.interval = interval;
	vars->matrix.width = vars->map.width;
	vars->matrix.height = vars->map.height;
	vars->matrix.center = (t_point){vars->img.width / 2, \
	vars->img.height / 2, 0, 0};
}

void	malloc_point_matrix(t_matrix *matrix)
{
	int	i;

	matrix->data = (t_point **)malloc(sizeof(t_point *) * matrix->height);
	if (NULL == matrix->data)
		exit_error("Error malloc vars->matrix", 1);
	i = 0;
	while (i < matrix->height)
	{
		matrix->data[i] = (t_point *)malloc(sizeof(t_point) * matrix->width);
		if (NULL == matrix->data[i])
			exit_error("Error malloc vars->matrix", 1);
		i++;
	}
}

void	get_matrix_start_point(t_vars *vars)
{
	int		w_matrix;
	int		h_matrix;
	t_point	center;

	w_matrix = vars->matrix.interval * vars->map.width;
	h_matrix = vars->matrix.interval * vars->map.height;
	center = vars->matrix.center;
	vars->matrix.data[0][0].x = center.x - (w_matrix / 2);
	vars->matrix.data[0][0].y = center.y - (h_matrix / 2);
}

void	fill_matrix_as_map(t_vars *vars, int interval)
{
	t_matrix	*matrix;
	int			i;
	int			j;

	matrix = &vars->matrix;
	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			matrix->data[i][j].x = matrix->data[0][0].x + (interval * j);
			matrix->data[i][j].y = matrix->data[0][0].y + (interval * i);
			matrix->data[i][j].z = vars->map.data[0][i][j] * interval / 10;
			matrix->data[i][j].color = vars->map.data[1][i][j];
			j++;
		}
		i++;
	}
}
