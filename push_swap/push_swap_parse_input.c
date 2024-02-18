/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:37:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/18 20:33:49 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_arr(int arr_size, char **strings, int *arg_arr)
{
	int	i;
	int	err_flag;

	i = 0;
	while (i < arr_size)
	{
		arg_arr[i] = ft_atoi_safe(strings[i], &err_flag);
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

int	rank_based_indexing(int **arr, int size)
{
	int	*arr_idx;
	int	max_idx;
	int	rank;
	int	i;

	arr_idx = (int *)ft_calloc(size, sizeof(*arr_idx));
	if (NULL == arr_idx)
		return (-1);
	rank = size - 1;
	while (0 <= rank)
	{
		max_idx = -1;
		i = 0;
		while (i < size)
		{
			if (0 == arr_idx[i] && (max_idx == -1 || (*arr)[max_idx] < (*arr)[i]))
				max_idx = i;
			i++;
		}
		arr_idx[max_idx] = rank;
		rank--;
	}
	free(*arr);
	*arr = arr_idx;
	return (0);
}

int	init_stack_with_index(t_stack *stack_a, int *arg_arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (-1 == stack_add_bottom(stack_a, arg_arr[i]))
		{
			free_stack(stack_a);
			return (-1);
		}
		i++;
	}
	stack_a->size = arr_size;
	return (0);
}

int	add_ternary_info_to_stack(t_stack *stack_a)
{
	stack_a->max_digits = get_max_digits(stack_a);
	if (-1 == add_ternary_value(stack_a))
		return (-1);
	return (0);
}
