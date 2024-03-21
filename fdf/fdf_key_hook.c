/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:44:26 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/21 21:46:30 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (ESC_KEY == keycode)
		exit(0);
	my_mlx_clear_window(vars);
	if (W_KEY == keycode)
		transform_coordinates(vars, rotate_x, ((M_PI * 5.0) / 180.0));
	if (S_KEY == keycode)
		transform_coordinates(vars, rotate_x, (-(M_PI * 5.0) / 180.0));
	if (A_KEY == keycode)
		transform_coordinates(vars, rotate_y, ((M_PI * 5.0) / 180.0));
	if (D_KEY == keycode)
		transform_coordinates(vars, rotate_y, (-(M_PI * 5.0) / 180.0));
	if (Q_KEY == keycode)
		transform_coordinates(vars, rotate_z, (-(M_PI * 5.0) / 180.0));
	if (E_KEY == keycode)
		transform_coordinates(vars, rotate_z, ((M_PI * 5.0) / 180.0));
	if (PLUS_KEY == keycode)
		zoom_in(vars);
	if (MINUS_KEY == keycode)
		zoom_out(vars);
	create_wireframe(vars);
	mlx_put_image_to_window(vars->mlx, vars->win.ptr, vars->img.ptr, 0, 0);
	return (0);
}

void	my_mlx_clear_window(t_vars *vars)
{
	ft_memset(vars->img.data, 0, vars->img.size_line * vars->img.height);
}

void	zoom_in(t_vars *vars)
{
	t_point	**matrix;
	t_point	center;
	int		i;
	int		j;
	int		m;
	int		n;

	m = 21;
	n = 1;
	matrix = vars->matrix.data;
	center = vars->img.center;
	i = 0;
	while (i < vars->matrix.height)
	{
		j = 0;
		while (j < vars->matrix.width)
		{
			matrix[i][j].x = ((m * matrix[i][j].x) - (n * center.x)) / (m - n);
			matrix[i][j].y = ((m * matrix[i][j].y) - (n * center.y)) / (m - n);
			matrix[i][j].z = ((m * matrix[i][j].z) - (n * center.z)) / (m - n);
			j++;
		}
		i++;
	}
}

void	zoom_out(t_vars *vars)
{
	t_point	**matrix;
	t_point	center;
	int		i;
	int		j;
	int		m;
	int		n;

	m = 20;
	n = 1;
	matrix = vars->matrix.data;
	center = vars->img.center;
	i = 0;
	while (i < vars->matrix.height)
	{
		j = 0;
		while (j < vars->matrix.width)
		{
			matrix[i][j].x = ((m * matrix[i][j].x) + (n * center.x)) / (m + n);
			matrix[i][j].y = ((m * matrix[i][j].y) + (n * center.y)) / (m + n);
			matrix[i][j].z = ((m * matrix[i][j].z) + (n * center.z)) / (m + n);
			j++;
		}
		i++;
	}
}
