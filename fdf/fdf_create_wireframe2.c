/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_wireframe2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:06:07 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/23 21:26:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getcolor(t_line *line, t_point point)
{
	float	p;
	int		r;
	int		g;
	int		b;

	p = (line->p1.y - point.y) / (line->p1.y - line->p2.y);
	r = get_r(line->p1.color) + \
	(p * (get_r(line->p2.color) - get_r(line->p1.color)));
	g = get_g(line->p1.color) + \
	(p * (get_g(line->p2.color) - get_g(line->p1.color)));
	b = get_b(line->p1.color) + \
	(p * (get_b(line->p2.color) - get_b(line->p1.color)));
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	hgetcolor(t_line *line, t_point point)
{
	float	p;
	int		r;
	int		g;
	int		b;

	p = (line->p1.x - point.x) / (line->p1.x - line->p2.x);
	r = get_r(line->p1.color) + \
	(p * (get_r(line->p2.color) - get_r(line->p1.color)));
	g = get_g(line->p1.color) + \
	(p * (get_g(line->p2.color) - get_g(line->p1.color)));
	b = get_b(line->p1.color) + \
	(p * (get_b(line->p2.color) - get_b(line->p1.color)));
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
