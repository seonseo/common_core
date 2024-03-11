#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_win
{
	int	width;
	int	height;
}	t_win;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	t_point	pos;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	t_win	*win;
	t_img	*img;
}	t_vars;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	paint_img_with_color(t_img *img, int width, int height, int color);

int		draw_circle(t_img *img, t_point center, int radius, int color);
double	distance_between_points(t_point p1, t_point p2);

int		render_next_frame(t_vars *vars);

int		key_hook(int keycode, void *param);

#endif
