/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:25:41 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/15 19:26:14 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_func(int x, t_line *line)
{
	double y;
	double m;
	double b;

	m = slope_calc(line);
	b = y_intercept_calc(line);
	y = (m * x) + b;
	return ((int)y);
}

double	slope_calc(t_line *line)
{
	double x1;
	double x2;
	double y1;
	double y2;

	x1 = (double)line->p1.x;
	x2 = (double)line->p2.x;
	y1 = (double)line->p1.y;
	y2 = (double)line->p2.y;
	return ((y2 - y1) / (x2 - x1));
}

double	y_intercept_calc(t_line *line)
{
	double x1;
	double x2;
	double y1;
	double y2;

	x1 = (double)line->p1.x;
	x2 = (double)line->p2.x;
	y1 = (double)line->p1.y;
	y2 = (double)line->p2.y;
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
