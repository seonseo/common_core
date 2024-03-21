/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric_projection1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:41:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/21 19:39:00 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point, t_point *center, double theta)
{
    double		y;
    double		z;

	y = point->y - center->y;
	z = point->z - center->z;
    point->y = (y * cos(theta)) - (z * sin(theta));
    point->z = (y * sin(theta)) + (z * cos(theta));
	point->y += center->y;
	point->z += center->z;
}

void	rotate_y(t_point *point, t_point *center, double theta)
{
    double		z;
    double		x;
    
	z = point->z - center->z;
	x = point->x - center->x;
    point->z = (z * cos(theta)) - (x * sin(theta));
    point->x = (z * sin(theta)) + (x * cos(theta));
	point->z += center->z;
	point->x += center->x;
}

void	rotate_z(t_point *point, t_point *center, double theta)
{
    double		x;
    double		y;

	x = point->x - center->x;
	y = point->y - center->y;
    point->x = (x * cos(theta)) - (y * sin(theta));
    point->y = (x * sin(theta)) + (y * cos(theta));
	point->x += center->x;
	point->y += center->y;
}
