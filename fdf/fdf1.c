/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:30:21 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/20 18:17:47 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	
	vars->win.width = 1080;
	vars->win.height = 1080;
	vars->win.ptr = mlx_new_window(vars->mlx, vars->win.width, vars->win.height, "fdf");

	vars->img.width = vars->win.width;
	vars->img.height = vars->win.height;
	vars->img.center = (t_point){vars->win.width / 2, vars->win.height / 2, 0};
	vars->img.ptr = mlx_new_image(vars->mlx, vars->img.width, vars->img.height);
	vars->img.data = mlx_get_data_addr(vars->img.ptr, &vars->img.bits_per_pixel, &vars->img.size_line, &vars->img.endian);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}
