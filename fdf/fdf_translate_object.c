/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:27:31 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/23 21:30:19 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_object(t_vars *vars, void (*translate)(t_point *))
{
	t_point	**matrix;
	int		i;
	int		j;

	matrix = vars->matrix.data;
	i = 0;
	while (i < vars->matrix.height)
	{
		j = 0;
		while (j < vars->matrix.width)
		{
			translate(&matrix[i][j]);
			j++;
		}
		i++;
	}
}

void	translate_right(t_point *point)
{
	point->x += 5;
}

void	translate_left(t_point *point)
{
	point->x -= 5;
}

void	translate_up(t_point *point)
{
	point->y -= 5;
}

void	translate_down(t_point *point)
{
	point->y += 5;
}
