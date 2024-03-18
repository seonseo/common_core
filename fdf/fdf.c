/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:01:42 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/17 22:04:53 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	leak_check(){system("leaks fdf");}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (2 != argc)
		exit_error("invalid argument", 0);
	parse_input_to_int_matrix(argv[1], &vars.map);
	init_vars(&vars);
	convert_map_to_point_matrix(&vars, 10);
	isometric_projection(&vars);
	create_wireframe(&vars);
	
	mlx_put_image_to_window(vars.mlx, vars.win.ptr, vars.img.ptr, 0, 0);
	mlx_hook(vars.win.ptr, CLOSE_WINDOW, 0, exit_no_error, NULL);
	mlx_key_hook(vars.win.ptr, key_hook, NULL);
	mlx_loop(vars.mlx);
	return (0);
}

