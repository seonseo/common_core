/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:41:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/20 22:08:16 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_coordinates(t_vars *vars)
{
	t_point	**matrix;
	int		**map;
	int		interval;
	int		i;
	int		j;

	interval = vars->matrix.interval;
	matrix = vars->matrix.data;
	map = vars->map.data;
	i = 0;
	while (i < vars->matrix.height)
	{
		j = 0;
		while (j < vars->matrix.width)
		{
			rotate_z(&matrix[i][j], M_PI * 45.0 / 180.0);
			rotate_x(&matrix[i][j], asin(tan(M_PI / 6.0)));
			// isometric_projection(&matrix[i][j]);
			j++;
		}
		i++;
	}
	center_shape(vars);
}

void isometric_projection(t_point *point)
{
    float theta;
    int x = point->x;
    int y = point->y;
	int	z = point->z;
    
	theta = M_PI / 6.0;
    point->x = (x - y) * cos(theta);
    point->y = (x + y) * sin(theta) - z;
}

void center_shape(t_vars *vars)
{
	t_matrix	*matrix;
    int			minX = INT_MAX;
	int			maxX = INT_MIN;
	int			minY = INT_MAX;
	int			maxY = INT_MIN;
    
	matrix = &vars->matrix;
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            if (matrix->data[i][j].x < minX) minX = matrix->data[i][j].x;
            if (matrix->data[i][j].x > maxX) maxX = matrix->data[i][j].x;
            if (matrix->data[i][j].y < minY) minY = matrix->data[i][j].y;
            if (matrix->data[i][j].y > maxY) maxY = matrix->data[i][j].y;
        }
    }
    int offsetX = (vars->img.width - (maxX - minX)) / 2 - minX;
    int offsetY = (vars->img.height - (maxY - minY)) / 2 - minY;
    for (int i = 0; i < matrix->height; i++)
	{
        for (int j = 0; j < matrix->width; j++)
		{
            matrix->data[i][j].x += offsetX;
            matrix->data[i][j].y += offsetY;
        }
    }
}

// void	transform_coordinate(t_point *point, int z)
// {
// 	const double	first[3][1] = {{point->x}, \
// 									{point->y}, \
// 									{z}};
// 	const double	second[3][3] = {{sqrt(3) / 2,	-sqrt(3) / 2,	0}, \
// 									{1.0 / 2.0,		1.0 / 2.0,		0}, \
// 									{0,				0,				1}};
// 	double			result[3][1];

// 	multiply_matrix(first, second, result);
// 	point->x = (int)result[0][0];
// 	point->y = (int)result[1][0];
// }

// void	multiply_matrix(const double (*first)[1], \
// const double (*second)[3], double (*result)[1])
// {
// 	int	i;
// 	int	k;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		result[i][0] = 0;
// 		k = 0;
// 		while (k < 3)
// 		{
// 			result[i][0] += first[k][0] * second[i][k];
// 			k++;
// 		}
// 		i++;
// 	}
// }
