/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:17:50 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 16:52:36 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_digits(t_stack *stack_a)
{
	int		max_digits;
	int		max_value;

	max_value = (stack_a->size) - 1;
	max_digits = 0;
	while (1)
	{
		max_value /= 3;
		max_digits++;
		if (0 == max_value)
			break ;
	}
	return (max_digits);
}

int	add_ternary_value(t_stack *stack_a)
{
	t_node	*curr;

	curr = stack_a->top;
	while (curr)
	{
		if (-1 == malloc_ternary_value(curr, stack_a->max_digits))
			return (-1);
		decimal_to_ternary(curr, stack_a->max_digits);
		curr = curr->lower;
	}
	return (0);
}

void	update_ternary_value(t_stack *stack_a)
{
	t_node	*curr;

	curr = stack_a->top;
	while (curr)
	{
		decimal_to_ternary(curr, stack_a->max_digits);
		curr = curr->lower;
	}
}

int	malloc_ternary_value(t_node *curr, int max_digits)
{
	curr->ternary_value = (int *)malloc(sizeof(int) * max_digits);
	if (NULL == curr->ternary_value)
		return (-1);
	return (0);
}

void	decimal_to_ternary(t_node *curr, int max_digits)
{
	int	i;
	int	curr_value;

	curr_value = curr->value;
	i = 0;
	while (i < max_digits)
	{
		(curr->ternary_value)[i] = curr_value % 3;
		curr_value /= 3;
		i++;
	}
}
