/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_convert_map_to_point_matrix.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:06:53 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/17 20:51:08 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_map_to_point_matrix(t_vars *vars, int interval)
{
	t_point		start_point;
	t_matrix	*matrix;
	int			i;
	int			j;

	matrix = &vars->matrix;
	matrix->interval = interval;
	matrix->width = vars->map.width;
	matrix->height = vars->map.height;
	malloc_point_matrix(matrix);
	get_matrix_start_point(vars);
	start_point = matrix->data[0][0];
	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			matrix->data[i][j].x = start_point.x + (interval * j);
			matrix->data[i][j].y = start_point.y + (interval * i);
			j++;
		}
		i++;
	}
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
	center = (t_point){(vars->img.width / 2), (vars->img.height / 2)};
	vars->matrix.data[0][0].x = center.x - (w_matrix / 2);
	vars->matrix.data[0][0].y = center.y - (h_matrix / 2);
}
