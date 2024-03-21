/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_wireframe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:24:45 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/21 20:41:27 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_wireframe(t_vars *vars)
{
	t_point	**matrix;
	int	width;
	int	height;
	int	x;
	int	y;

	matrix = vars->matrix.data;
	width = vars->map.width;
	height = vars->map.height;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y + 1 <	height)
				draw_line(&vars->img,\
				 (t_line){matrix[y][x], matrix[y + 1][x]});
			if (x + 1 < width)
				draw_line(&vars->img,\
				 (t_line){matrix[y][x], matrix[y][x + 1]});
			x++;
		}
		y++;
	}
}

void	draw_line(t_img *img, t_line line)
{
	line.p1.x = round(line.p1.x);
	line.p1.y = round(line.p1.y);
	line.p2.x = round(line.p2.x);
	line.p2.y = round(line.p2.y);
	if (line.p1.x == line.p2.x)
		draw_vertical_line(img, &line);
	else
		draw_non_vertical_line(img, &line);
}

void	draw_vertical_line(t_img *img, t_line *line)
{
	int	x;
	int	y;
	int	y_max;

	x = line->p1.x;
	if (0 <= x && x < img->width)
	{
		y_max = ft_max(line->p1.y, line->p2.y);
		y = ft_min(line->p1.y, line->p2.y);
		while (y <= y_max && 0 <= y && y < img->height)
		{
			my_mlx_pixel_put(img, x, y, 0x00ffffff);
			y++;
		}
	}
}

void	draw_non_vertical_line(t_img *img, t_line *line)
{
	int	x;
	int	y;
	int	y_next;
	int	x_max;

	x_max = ft_max(line->p1.x, line->p2.x);
	x = ft_min(line->p1.x, line->p2.x);
	while (x <= x_max && 0 <= x && x < img->width)
	{
		y = line_func(x, line);
		y_next = line_func(x + 1, line);
		if (y == y_next && 0 <= y && y < img->height)
			my_mlx_pixel_put(img, x, y, 0x00ffffff);
		while (y != y_next && 0 <= y && y < img->height)
		{
			my_mlx_pixel_put(img, x, y, 0x00ffffff);
			if (x == x_max)
				break;
			if (y < y_next)
				y++;
			if (y > y_next)
				y--;
		}
		x++;
	}
}
