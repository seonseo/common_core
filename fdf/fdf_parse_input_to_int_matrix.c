/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_input_to_int_matrix.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:35:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/23 19:12:42 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_input_to_int_matrix(char *pathname, t_map *map)
{
	int		fd;
	char	**strs;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening file", 1);
	strs = read_lines(fd);
	close(fd);
	malloc_map_data(map, strs);
	fill_map_data(map, strs);
	return (0);
}

char	**read_lines(int fd)
{
	char	*str;
	char	*buf;
	char	*join;
	char	**strs;

	str = NULL;
	while (1)
	{
		buf = get_next_line(fd);
		if (NULL == buf)
			break ;
		join = ft_strjoin(str, buf);
		if (NULL == join)
			exit_error("Error ft_strjoin", 1);
		free(buf);
		free(str);
		str = join;
	}
	strs = ft_split(str, '\n');
	if (NULL == strs)
		exit_error("Error ft_split", 1);
	free(str);
	return (strs);
}

void	malloc_map_data(t_map *map, char **strs)
{
	int	i;
	int	j;

	map->height = ft_ptrslen((void **)strs);
	map->width = ft_wordcount(strs[0], ' ');
	map->data = (int ***)malloc(sizeof(int **) * 2);
	if (NULL == map->data)
		exit_error("Error malloc for map_data", 1);
	i = 0;
	while (i < 2)
	{
		map->data[i] = (int **)malloc(sizeof(int *) * map->height);
		if (NULL == map->data[i])
			exit_error("Error malloc for map_data", 1);
		j = 0;
		while (j < map->height)
		{
			map->data[i][j] = (int *)malloc(sizeof(int) * map->width);
			if (NULL == map->data[i][j])
				exit_error("Error malloc for map_data", 1);
			j++;
		}
		i++;
	}
}

void	fill_map_data(t_map *map, char **strs)
{
	int	row;

	row = 0;
	while (row < map->height)
	{
		str_to_int_arr(strs[row], map, row);
		free(strs[row]);
		row++;
	}
	free(strs);
}
