/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_coordinates1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:41:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/20 19:14:18 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point, float angle)
{
    float	theta;
    int		y;
    int		z;

	y = point->y;
	z = point->z;
	theta = angle;
    point->y = (y * cos(theta)) - (z * sin(theta));
    point->z = (y * sin(theta)) + (z * cos(theta));
}

void	rotate_y(t_point *point, float angle)
{
    float	theta;
    int		z;
    int		x;
    
	z = point->z;
	x = point->x;
	theta = angle;
    point->z = (z * cos(theta)) - (x * sin(theta));
    point->x = (z * sin(theta)) + (x * cos(theta));
}

void	rotate_z(t_point *point, float angle)
{
    float	theta;
    int		x;
    int		y;

	x = point->x;
	y = point->y;
	theta = angle;
    point->x = (x * cos(theta)) - (y * sin(theta));
    point->y = (x * sin(theta)) + (y * cos(theta));
}
