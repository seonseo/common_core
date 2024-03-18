/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:41:01 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/17 20:58:51 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

# define CLOSE_WINDOW 17

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
}	t_line;

typedef struct s_win
{
	void	*ptr;
	int		width;
	int		height;
}	t_win;

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	t_point	pos;
}	t_img;

typedef struct s_map
{
	int	**data;
	int	width;
	int	height;
}	t_map;

typedef struct s_matrix
{
	t_point	**data;
	int		width;
	int		height;
	int		interval;
}	t_matrix;

typedef struct s_vars
{
	void		*mlx;
	t_win		win;
	t_map		map;
	t_matrix	matrix;
	t_img		img;
}	t_vars;

//fdf.c
int		main(int argc, char **argv);
//fdf1.c
void	init_vars(t_vars *vars);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	isometric_projection(t_vars *vars);
void	transform_coordinate(t_point *point, int z);
void	center_shape(t_vars *vars);
// void	multiply_matrix(const double (*first)[1], const double (*second)[3], double (*result)[1]);

//fdf_parse_input_to_int_matrix.c
int		parse_input_to_int_matrix(char *pathname, t_map *map);
char	**read_lines(int fd);
void	malloc_map_data(t_map *map, char **strs);
void	fill_map_data(t_map *map, char **strs);
//fdf_parse_input_to_int_matrix1.c
size_t	ft_ptrslen(void **ptrs);
int		*str_to_int_arr(char *str, int len);

//fdf_convert_map_to_point_matrix.c
void	convert_map_to_point_matrix(t_vars *vars, int interval);
void	malloc_point_matrix(t_matrix *matrix);
void	get_matrix_start_point(t_vars *vars);

// fdf_create_wireframe.c
void	create_wireframe(t_vars *vars);
void	draw_line(t_img *img, t_line *line);
void	draw_vertical_line(t_img *img, t_line *line);
void	draw_non_vertical_line(t_img *img, t_line *line);
// fdf_create_wireframe1.c
int		line_func(int x, t_line *line);
double	slope_calc(t_line *line);
double	y_intercept_calc(t_line *line);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

//fdf_exit_error.c
void	exit_error(char *err_msg, int perror_flag);
int		exit_no_error(void);

//fdf_key_hook.c
int		key_hook(int keycode);
#endif
