/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:30:21 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/26 18:48:38 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win.width = 1080;
	vars->win.height = 1080;
	vars->win.ptr = mlx_new_window(vars->mlx, \
	vars->win.width, vars->win.height, "fdf");
	vars->img.width = vars->win.width;
	vars->img.height = vars->win.height;
	vars->img.ptr = mlx_new_image(vars->mlx, vars->img.width, vars->img.height);
	vars->img.data = mlx_get_data_addr(vars->img.ptr, \
	&vars->img.bits_per_pixel, &vars->img.size_line, &vars->img.endian);
	vars->event.left_click = 0;
	vars->event.mouse_move = 0;
}

void	setup_event_hooks(t_vars *vars)
{
	mlx_hook(vars->win.ptr, CLOSE_WINDOW, 0, exit_no_error, NULL);
	mlx_hook(vars->win.ptr, PRESS_KEY, 0, key_hook, vars);
	mlx_hook(vars->win.ptr, PRESS_BUTTON, 0, \
	mouse_button_press_hook, &vars->event);
	mlx_hook(vars->win.ptr, RELEASE_BUTTON, 0, \
	mouse_button_release_hook, &vars->event);
	mlx_hook(vars->win.ptr, MOVE_MOUSE, 0, mouse_move_hook, vars);
}

void	draw_next_frame(t_vars *vars)
{
	my_mlx_clear_window(vars);
	create_wireframe(vars);
	mlx_put_image_to_window(vars->mlx, vars->win.ptr, vars->img.ptr, 0, 0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)dst = color;
}

void	my_mlx_clear_window(t_vars *vars)
{
	ft_memset(vars->img.data, 0, vars->img.size_line * vars->img.height);
}
