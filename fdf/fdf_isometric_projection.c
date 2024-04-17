/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric_projection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:41:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/24 19:06:34 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_vars *vars)
{
	rotate_object(vars, \
	rotate_z, ((M_PI * 45.0) / 180.0));
	rotate_object(vars, \
	rotate_x, ((M_PI / 2.0) - asin(tan(M_PI / 6.0))));
}

void	rotate_object(t_vars *vars, \
void (*rotate)(t_point *, t_point *, float), float angle)
{
	t_point	**matrix;
	int		i;
	int		j;

	matrix = vars->matrix.data;
	i = 0;
	while (i < vars->matrix.height)
	{
		j = 0;
		while (j < vars->matrix.width)
		{
			rotate(&matrix[i][j], &vars->matrix.center, angle);
			j++;
		}
		i++;
	}
}

void	rotate_x(t_point *point, t_point *center, float theta)
{
	float	y;
	float	z;

	y = point->y - center->y;
	z = point->z - center->z;
	point->y = (y * cos(theta)) - (z * sin(theta));
	point->z = (y * sin(theta)) + (z * cos(theta));
	point->y += center->y;
	point->z += center->z;
}

void	rotate_y(t_point *point, t_point *center, float theta)
{
	float	z;
	float	x;

	z = point->z - center->z;
	x = point->x - center->x;
	point->z = (z * cos(theta)) - (x * sin(theta));
	point->x = (z * sin(theta)) + (x * cos(theta));
	point->z += center->z;
	point->x += center->x;
}

void	rotate_z(t_point *point, t_point *center, float theta)
{
	float	x;
	float	y;

	x = point->x - center->x;
	y = point->y - center->y;
	point->x = (x * cos(theta)) - (y * sin(theta));
	point->y = (x * sin(theta)) + (y * cos(theta));
	point->x += center->x;
	point->y += center->y;
}
