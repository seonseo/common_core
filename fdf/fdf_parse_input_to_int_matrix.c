/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_input_to_int_matrix.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:35:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/21 21:57:30 by seonseo          ###   ########.fr       */
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

char **read_lines(int fd)
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
			break;
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
	map->height = ft_ptrslen((void **)strs);
	map->data = (int ***)malloc(sizeof(int **) * 2);
	if (NULL == map->data[0])
	map->data[0] = (int **)malloc(sizeof(int *) * map->height);
	if (NULL == map->data[0])
		exit_error("Error malloc for map_data", 1);
	map->data[1] = (int **)malloc(sizeof(int *) * map->height);
	if (NULL == map->data[1])
		exit_error("Error malloc for map_data", 1);
}

void	fill_map_data(t_map *map, char **strs)
{
	int	i;

	map->width = ft_wordcount(strs[0], ' ');
	i = 0;
	while (i < map->height)
	{
		(map->data)[i] = str_to_int_arr(strs[i], map->width);
		free(strs[i]);
		i++;
	}
	free(strs);
}
