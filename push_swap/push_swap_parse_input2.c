/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:17:50 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/19 17:53:47 by seonseo          ###   ########.fr       */
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
			break;
	}
	return (max_digits);
}

int	add_ternary_value(t_stack *stack_a)
{
	t_node	*curr;

	curr = stack_a->top;
	while (curr)
	{
		curr->ternary_value\
		 = decimal_to_ternary(curr->value, stack_a->max_digits);
		if (NULL == curr->ternary_value)
			return (-1);
		curr = curr->lower;
	}
	return (0);
}

int	*decimal_to_ternary(int value, int max_digits)
{
	int	*ternary_value;
	int	i;

	ternary_value = (int *)malloc(sizeof(*ternary_value) * max_digits);
	if (NULL == ternary_value)
		return (NULL);
	i = 0;
	while (i < max_digits)
	{
		ternary_value[i] = value % 3;
		value /= 3;
		i++;
	}
	return (ternary_value);
}
