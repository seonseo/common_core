/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:41:01 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/26 18:34:21 by seonseo          ###   ########.fr       */
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
# define PRESS_KEY 2
# define PRESS_BUTTON 4
# define RELEASE_BUTTON 5
# define MOVE_MOUSE 6
# define ESC_KEY 53
# define Q_KEY 12
# define W_KEY 13
# define E_KEY 14
# define R_KEY 15
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define MINUS_KEY 27
# define PLUS_KEY 24
# define ONE_KEY 18
# define TWO_KEY 19
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126

typedef struct s_point2d
{
	int	x;
	int	y;
}	t_point2d;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
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
}	t_img;

typedef struct s_map
{
	int	***data;
	int	width;
	int	height;
}	t_map;

typedef struct s_matrix
{
	t_point	**data;
	int		width;
	int		height;
	int		interval;
	t_point	center;
}	t_matrix;

typedef struct s_event
{
	t_point2d	mouse_pos;
	int			mouse_move;
	int			left_click;
}	t_event;

typedef struct s_vars
{
	void		*mlx;
	t_win		win;
	t_map		map;
	t_matrix	matrix;
	t_img		img;
	t_event		event;
}	t_vars;

//fdf.c
int		main(int argc, char **argv);
//fdf1.c
void	init_vars(t_vars *vars);
void	setup_event_hooks(t_vars *vars);
void	draw_next_frame(t_vars *vars);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	my_mlx_clear_window(t_vars *vars);

//fdf_parse_input_to_int_matrix.c
int		parse_input_to_int_matrix(char *pathname, t_map *map);
char	**read_lines(int fd);
void	malloc_map_data(t_map *map, char **strs);
void	fill_map_data(t_map *map, char **strs);
//fdf_parse_input_to_int_matrix1.c
size_t	ft_ptrslen(void **ptrs);
void	str_to_int_arr(char *str, t_map *map, int row);

//fdf_convert_map_to_point_matrix.c
void	convert_map_to_point_matrix(t_vars *vars, int interval);
void	init_matrix_member(t_vars *vars, int interval);
void	malloc_point_matrix(t_matrix *matrix);
void	get_matrix_start_point(t_vars *vars);
void	fill_matrix_as_map(t_vars *vars, int interval);

//fdf_isometric_projection.c
void	isometric_projection(t_vars *vars);
void	rotate_object(t_vars *vars, \
void (*rotate)(t_point *, t_point *, float), float angle);
void	rotate_x(t_point *point, t_point *center, float angle);
void	rotate_y(t_point *point, t_point *center, float angle);
void	rotate_z(t_point *point, t_point *center, float angle);

//fdf_create_wireframe.c
void	create_wireframe(t_vars *vars);
void	draw_line(t_img *img, t_line line);
void	draw_vertical_line(t_img *img, t_line *line);
void	draw_non_vertical_line(t_img *img, t_line *line);
// fdf_create_wireframe1.c
int		line_func(int x, t_line *line);
float	slope_calc(t_line *line);
float	y_intercept_calc(t_line *line);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
//fdf_create_wireframe2.c
int		getcolor(t_line *line, t_point point);
int		hgetcolor(t_line *line, t_point point);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

//fdf_translate_object.c
void	translate_object(t_vars *vars, void (*translate)(t_point *));
void	translate_right(t_point *point);
void	translate_left(t_point *point);
void	translate_up(t_point *point);
void	translate_down(t_point *point);

//fdf_exit_error.c
void	exit_error(char *err_msg, int perror_flag);
int		exit_no_error(void);

//fdf_key_hook.c
int		key_hook(int keycode, void *param);
void	key_hook_projection(int keycode, t_vars *vars);
void	key_hook_rotate(int keycode, t_vars *vars);
void	key_hook_translate(int keycode, t_vars *vars);
//fdf_key_hook1.c
void	key_hook_zoom(int keycode, t_vars *vars);
void	zoom_in(t_matrix *matrix);
void	zoom_out(t_matrix *matrix);

//fdf_mouse_move_hook.c
int		mouse_move_hook(int x, int y, void *param);
int		mouse_button_press_hook(int button, int x, int y, void *param);
int		mouse_button_release_hook(int button, int x, int y, void *param);
#endif
