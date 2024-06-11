/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_wireframe1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:25:41 by seonseo           #+#    #+#             */
/*   Updated: 2024/06/11 16:12:14 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_func(int x, t_line *line)
{
	float	y;
	float	m;
	float	b;

	m = slope_calc(line);
	b = y_intercept_calc(line);
	y = (m * x) + b;
	return ((int)round(y));
}

float	slope_calc(t_line *line)
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;

	x1 = line->p1.x;
	x2 = line->p2.x;
	y1 = line->p1.y;
	y2 = line->p2.y;
	return ((y2 - y1) / (x2 - x1));
}

float	y_intercept_calc(t_line *line)
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;

	x1 = line->p1.x;
	x2 = line->p2.x;
	y1 = line->p1.y;
	y2 = line->p2.y;
	return (y1 - (((y2 - y1) / (x2 - x1)) * x1));
}

int	ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
