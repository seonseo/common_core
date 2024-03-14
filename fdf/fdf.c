/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:01:42 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/14 20:42:01 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	leak_check(){system("leaks fdf");}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (2 != argc)
		error_exit("invalid argument", 0);
	parse_input(argv[1], &vars.map);
	init_vars(&vars);

	draw_line(&vars.img, (t_line){(t_point){0, 4}, (t_point){1, 5}});
	
	mlx_put_image_to_window(vars.mlx, vars.win.ptr, vars.img.ptr, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	
	vars->win.width = 1080;
	vars->win.height = 1080;
	vars->win.ptr = mlx_new_window(vars->mlx, vars->win.width, vars->win.height, "fdf");

	vars->img.width = vars->win.width;
	vars->img.height = vars->win.height;
	vars->img.ptr = mlx_new_image(vars->mlx, vars->img.width, vars->img.height);
	vars->img.data = mlx_get_data_addr(vars->img.ptr, &vars->img.bits_per_pixel, &vars->img.size_line, &vars->img.endian);
}

void	draw_line(t_img *img, t_line line)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->width)
	{
		y = line_func(x, line);
		if (0 <= y && y < img->height)
			my_mlx_pixel_put(img, x, y, 0x00ffffff);
		x++;
	}
}

int	line_func(int x, t_line line)
{
	double y;
	double m;
	double b;

	m = slope_calc(line);
	b = y_intercept_calc(line);
	y = (m * x) + b;
	return ((int)y);
}

double	slope_calc(t_line line)
{
	double x1;
	double x2;
	double y1;
	double y2;

	x1 = (double)line.p1.x;
	x2 = (double)line.p2.x;
	y1 = (double)line.p1.y;
	y2 = (double)line.p2.y;
	return ((y2 - y1) / (x2 - x1));
}

double	y_intercept_calc(t_line line)
{
	double x1;
	double x2;
	double y1;
	double y2;

	x1 = (double)line.p1.x;
	x2 = (double)line.p2.x;
	y1 = (double)line.p1.y;
	y2 = (double)line.p2.y;
	return (y1 - (((y2 - y1) / (x2 - x1)) * x1));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}

// void	paint_img_with_color(t_img *img, int color)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < img->height)
// 	{
		
// 		x = 0;
// 		while (x < img->width)
// 		{
// 			my_mlx_pixel_put(img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// int	key_hook(int keycode)
// {
// 	if (53 == keycode)
// 		exit(0);
// 	return (0);
// }

// int	close_window()
// {
// 	exit(0);
// }

void	print_map_data(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->col)
	{
		j = 0;
		while (j < map->row)
		{
			ft_printf("%d  ", map->data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
