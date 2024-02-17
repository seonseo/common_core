/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:17:50 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/17 22:18:13 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
