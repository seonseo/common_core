/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:01:42 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/11 21:05:01 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_vars	vars;
	t_img	circle;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "moving circle");
	vars.img = &circle;

	circle.width = 100;
	circle.height = 100;
	circle.img = mlx_new_image(vars.mlx, circle.width, circle.height);
	circle.addr = mlx_get_data_addr(circle.img, &circle.bits_per_pixel,\
	 &circle.size_line, &circle.endian);
	draw_circle(circle.img, (t_point){50, 50}, 50, 0x000000ff);
	circle.pos.x = 500;
	circle.pos.y = 500;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, circle.pos.x, circle.pos.y);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook

	return (0);
}

int	render_next_frame(t_vars *vars)
{
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(int*)dst = color;
}

void	paint_img_with_color(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}


int	draw_circle(t_img *img, t_point center, int radius, int color)
{
	t_point point;

	point.y = 0;
	while (point.y < img->height)
	{
		point.x = 0;
		while (point.x < img->width)
		{
			if ((int)distance_between_points(center, point) <= radius)
				my_mlx_pixel_put(img, point.x, point.y, color);
			else
				my_mlx_pixel_put(img, point.x, point.y, 0xff000000);
			point.x++;
		}
		point.y++;
	}
	return (0);
}

double distance_between_points(t_point p1, t_point p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

int	key_hook(int keycode, void *vars)
{
	if (53 == keycode)
		exit(0);
	if (123 == keycode)
		vars->img->pos->x -= 100;
	if (124 == keycode)
		vars->img->pos->x += 100;
	if (125 == keycode)
		vars->img->pos->y -= 100;
	if (126 == keycode)
		vars->img->pos->y += 100;
	paint_img_with_color(vars->img, )
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, circle.pos.x, circle.pos.y);
	return (0);
}
