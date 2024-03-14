/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:35:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/14 16:27:56 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_input(char *pathname, t_map *map)
{
	int		fd;
	char	**strs;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening file", 1);
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
			error_exit("Error ft_strjoin", 1);
		free(buf);
		free(str);
		str = join;
	}
	strs = ft_split(str, '\n');
	if (NULL == strs)
		error_exit("Error ft_split", 1);
	free(str);
	return (strs);
}

void	malloc_map_data(t_map *map, char **strs)
{
	map->col = ft_ptrslen((void **)strs);
	map->data = (int **)malloc(sizeof(int *) * map->col);
	if (NULL == map->data)
		error_exit("Error malloc for map_data", 1);
}

void	fill_map_data(t_map *map, char **strs)
{
	int	i;

	map->row = ft_wordcount(strs[0], ' ');
	i = 0;
	while (i < map->col)
	{
		(map->data)[i] = str_to_int_arr(strs[i], map->row);
		free(strs[i]);
		i++;
	}
	free(strs);
}
