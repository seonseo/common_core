/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:41:01 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/14 20:36:41 by seonseo          ###   ########.fr       */
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
	int	row;
	int	col;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	t_win	win;
	t_map	map;
	t_img	img;
}	t_vars;

//fdf.c
int		main(int argc, char **argv);
void	init_vars(t_vars *vars);

void	draw_line(t_img *img, t_line line);
int		line_func(int x, t_line line);
double	slope_calc(t_line line);
double	y_intercept_calc(t_line line);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//fdf_error_exit.c
void	error_exit(char *err_msg, int perror_flag);

//fdf_parse_input.c
int		parse_input(char *pathname, t_map *map);
char	**read_lines(int fd);
void	malloc_map_data(t_map *map, char **strs);
void	fill_map_data(t_map *map, char **strs);

//fdf_parse_input1.c
size_t	ft_ptrslen(void **ptrs);
int		*str_to_int_arr(char *str, int len);

//fdf.c
void	print_map_data(t_map *map);
// void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif
