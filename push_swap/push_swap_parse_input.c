/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:37:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 16:55:48 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_strs(int argc, char **argv, char ***strings)
{
	if (2 == argc)
	{
		*strings = ft_split(argv[1], ' ');
		if (NULL == *strings)
			return (-1);
	}
	else
		*strings = argv + 1;
	return (0);
}

int	get_args(t_arr *args, char **strings)
{
	args->size = ft_strslen(strings);
	args->arr = (int *)malloc(sizeof(*(args->arr)) * args->size);
	if (NULL == args->arr)
		return (-1);
	return (0);
}

void	free_strs(char ***strings)
{
	int	i;

	i = 0;
	while ((*strings)[i])
	{
		free((*strings)[i]);
		(*strings)[i] = NULL;
		i++;
	}
	free(*strings);
	*strings = NULL;
	strings = NULL;
}

int	fill_arr(t_arr *args, char **strings)
{
	size_t	i;
	int		err_flag;

	i = 0;
	while (i < args->size)
	{
		(args->arr)[i] = ft_atoi_safe(strings[i], &err_flag);
		if (-1 == err_flag)
			return (-1);
		i++;
	}
	return (0);
}
