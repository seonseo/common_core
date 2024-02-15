/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:37:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/15 22:14:12 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_arr(int argc, char **argv, int *arg_arr)
{
	int	i;
	int	err_flag;

	i = 1;
	while (i < argc)
	{
		arg_arr[i - 1] = ft_atoi_safe(argv[i], &err_flag);
		if (-1 == err_flag)
			return (-1);
		i++;
	}
	return (0);
}

int	check_dup_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	rank_based_indexing(int *arr, int size)
{
	int	*arr_index;
	int	max;
	int	rank;
	int	i;

	arr_index = (int *)ft_calloc(size, sizeof(*arr_index));
	rank = size - 1;
	while (0 <= rank)
	{
		max = -1;
		i = 0;
		while (i < size)
		{
			if (0 == arr_index[i] && (max == -1 || arr[max] < arr[i]))
				max = i;
			i++;
		}
		arr_index[max] = rank;
		rank--;
	}

}

int	init_stack(t_stack *stack_a, int *arg_arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (-1 == stack_add_top(stack_a, arg_arr[i]))
		{
			free_stack(stack_a);
			return (-1);
		}
		i++;
	}
	stack_a->size = arr_size;
	return (0);
}
