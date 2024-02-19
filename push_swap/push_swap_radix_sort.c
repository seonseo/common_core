/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:52:40 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/19 20:53:25 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ternary_radix_sort(t_stack *stack_a, int print)
{
	t_stack	stack_b;
	int		digit_idx;
	int		max_digits;

	if (-1 == add_ternary_info_to_stack(stack_a))
		return (-1);
	stack_b = (t_stack){};
	max_digits = stack_a->max_digits;
	digit_idx = 0;
	while (digit_idx + 1 < max_digits)
	{
		digit_sort_from_a(stack_a, &stack_b, digit_idx, print);
		digit_idx++;
		reassemble_in_stack_b(stack_a, &stack_b, print);
		digit_sort_from_b(stack_a, &stack_b, digit_idx, print);
		digit_idx++;
		reassemble_in_stack_a(stack_a, &stack_b, print);
	}
	while (digit_idx < max_digits)
	{
		digit_sort_from_a(stack_a, &stack_b, digit_idx, print);
		digit_idx++;
		reassemble_in_stack_a(stack_a, &stack_b, print);
	}
	return (0);
}

void	modify_arguments(t_arr *args, t_stack *stack_a)
{
	size_t	i;
	
	i = 0;
	while (i < args->size)
	{
		(args->arr)[i] = get_nth_value(stack_a, (args->arr)[i]);
		i++;
	}
}

int	get_nth_value(t_stack *stack, size_t n)
{
	t_node	*curr;
	size_t	i;

	curr = stack->top;
	i = 0;
	while (i < n)
	{
		curr = curr->lower;
		i++;
	}
	return (curr->value);
}
