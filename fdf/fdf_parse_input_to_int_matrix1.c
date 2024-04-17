/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_input_to_int_matrix1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:36:16 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/23 19:12:58 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_depth_and_color(char *str, t_map *map, int row, int col);
static int	color_str_to_i(const char *str);
static int	digit_ctoi(char c);

void	str_to_int_arr(char *str, t_map *map, int row)
{
	char	**strs;
	int		col;

	strs = ft_split(str, ' ');
	col = 0;
	while (col < map->width)
	{
		fill_depth_and_color(strs[col], map, row, col);
		free(strs[col]);
		col++;
	}
	free(strs);
}

static void	fill_depth_and_color(char *str, t_map *map, int row, int col)
{
	char	**strs;

	strs = ft_split(str, ',');
	map->data[0][row][col] = ft_atoi(strs[0]);
	free(strs[0]);
	if (NULL != strs[1])
		map->data[1][row][col] = color_str_to_i(strs[1]);
	else
		map->data[1][row][col] = 0x00ffffff;
	free(strs[1]);
	free(strs);
}

static int	color_str_to_i(const char *str)
{
	int				i;
	unsigned int	number;

	number = 0;
	if (0 != ft_strncmp(str, "0x", 2))
		return (0);
	i = 2;
	while (-1 != digit_ctoi(str[i]))
	{
		number = number * 16 + digit_ctoi(str[i]);
		i++;
	}
	return ((int)(number));
}

static int	digit_ctoi(char c)
{
	char	digit_c;
	int		i;

	digit_c = (char)ft_tolower(c);
	i = 0;
	while (i < 16)
	{
		if (digit_c == "0123456789abcdef"[i])
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_ptrslen(void **ptrs)
{
	size_t	len;

	len = 0;
	while (ptrs[len])
		len++;
	return (len);
}
