/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:52:40 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 16:52:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ternary_radix_sort(t_stack *stack_a, int print)
{
	t_stack	stack_b;
	int		max_digits;
	int		digit_idx;

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
	if (digit_idx < max_digits)
	{
		digit_sort_from_a(stack_a, &stack_b, digit_idx, print);
		reassemble_in_stack_a(stack_a, &stack_b, print);
	}
}

void	ternary_radix_sort_1(t_stack *stack_a, int print)
{
	t_stack	stack_b;
	int		max_digits;
	int		digit_idx;

	stack_b = (t_stack){};
	max_digits = stack_a->max_digits;
	digit_idx = 0;
	while (1)
	{
		digit_sort_from_a(stack_a, &stack_b, digit_idx, print);
		digit_idx++;
		reassemble_in_stack_b(stack_a, &stack_b, print);
		if (digit_idx + 2 == max_digits)
			break ;
		digit_sort_from_b(stack_a, &stack_b, digit_idx, print);
		digit_idx++;
		reassemble_in_stack_a(stack_a, &stack_b, print);
	}
	digit_sort_from_b_last(stack_a, &stack_b, digit_idx, print);
	reassemble_in_stack_a_last(stack_a, &stack_b, print);
}

void	modify_args(t_arr *args, t_stack *stack_a)
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

void	update_stack_with_modified_args(t_arr *args, t_stack *stack_a)
{
	t_node	*curr;
	size_t	i;

	i = 0;
	curr = stack_a->top;
	while (curr)
	{
		curr->value = (args->arr)[i];
		i++;
		curr = curr->lower;
	}
}
