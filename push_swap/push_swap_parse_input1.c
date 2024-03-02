/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:37:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/02 15:18:46 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_dup_arr(t_arr *args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < args->size)
	{
		j = i + 1;
		while (j < args->size)
		{
			if ((args->arr)[i] == (args->arr)[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	rank_based_indexing(t_arr *args)
{
	int		*arr_idx;
	int		max_idx;
	int		rank;
	size_t	i;

	arr_idx = (int *)ft_calloc(args->size, sizeof(*arr_idx));
	if (NULL == arr_idx)
		return (-1);
	rank = args->size - 1;
	while (0 <= rank)
	{
		max_idx = -1;
		i = -1;
		while (++i < args->size)
			if (0 == arr_idx[i] && \
			(max_idx == -1 || (args->arr)[max_idx] < (args->arr)[i]))
				max_idx = i;
		arr_idx[max_idx] = rank;
		rank--;
	}
	free(args->arr);
	args->arr = arr_idx;
	return (0);
}

int	init_stack_with_args(t_arr *args, t_stack *stack_a)
{
	size_t	i;

	i = 0;
	while (i < args->size)
	{
		if (-1 == stack_add_bottom(stack_a, (args->arr)[i]))
			return (-1);
		i++;
	}
	stack_a->size = args->size;
	return (0);
}
