/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:01:42 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/20 21:58:35 by seonseo          ###   ########.fr       */
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
	convert_map_to_point_matrix(&vars, 30);
	transform_coordinates(&vars);
	create_wireframe(&vars);

	mlx_put_image_to_window(vars.mlx, vars.win.ptr, vars.img.ptr, 0, 0);
	mlx_hook(vars.win.ptr, CLOSE_WINDOW, 0, exit_no_error, NULL);
	mlx_key_hook(vars.win.ptr, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
//zoom in, out
//rotate


// void	print_matrix(t_vars *vars)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < vars->matrix.height)
// 	{
// 		j = 0;
// 		while (j < vars->matrix.width)
// 		{
// 			my_mlx_pixel_put(&vars->img, vars->matrix.data[i][j].x,\
// 			 vars->matrix.data[i][j].y, 0x00ff0000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

