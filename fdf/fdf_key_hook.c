/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:44:26 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/26 16:24:46 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (ESC_KEY == keycode)
		exit(0);
	key_hook_projection(keycode, vars);
	key_hook_rotate(keycode, vars);
	key_hook_translate(keycode, vars);
	key_hook_zoom(keycode, vars);
	draw_next_frame(vars);
	return (0);
}

void	key_hook_projection(int keycode, t_vars *vars)
{
	if (ONE_KEY == keycode)
	{
		vars->matrix.center = (t_point){vars->img.width / 2, \
		vars->img.height / 2, 0, 0};
		get_matrix_start_point(vars);
		fill_matrix_as_map(vars, 20);
		isometric_projection(vars);
	}
	else if (TWO_KEY == keycode)
	{
		vars->matrix.center = (t_point){vars->img.width / 2, \
		vars->img.height / 2, 0, 0};
		get_matrix_start_point(vars);
		fill_matrix_as_map(vars, 20);
	}
}

void	key_hook_rotate(int keycode, t_vars *vars)
{
	if (W_KEY == keycode)
		rotate_object(vars, rotate_x, ((M_PI * 5.0) / 180.0));
	else if (S_KEY == keycode)
		rotate_object(vars, rotate_x, (-(M_PI * 5.0) / 180.0));
	else if (A_KEY == keycode)
		rotate_object(vars, rotate_y, ((M_PI * 5.0) / 180.0));
	else if (D_KEY == keycode)
		rotate_object(vars, rotate_y, (-(M_PI * 5.0) / 180.0));
	else if (Q_KEY == keycode)
		rotate_object(vars, rotate_z, (-(M_PI * 5.0) / 180.0));
	else if (E_KEY == keycode)
		rotate_object(vars, rotate_z, ((M_PI * 5.0) / 180.0));
}

void	key_hook_translate(int keycode, t_vars *vars)
{
	if (LEFT_KEY == keycode)
	{
		translate_object(vars, translate_left);
		vars->matrix.center.x -= 5;
	}
	else if (RIGHT_KEY == keycode)
	{
		translate_object(vars, translate_right);
		vars->matrix.center.x += 5;
	}
	else if (DOWN_KEY == keycode)
	{
		translate_object(vars, translate_down);
		vars->matrix.center.y += 5;
	}
	else if (UP_KEY == keycode)
	{
		translate_object(vars, translate_up);
		vars->matrix.center.y -= 5;
	}
}
