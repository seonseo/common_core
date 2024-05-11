/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:52:40 by seonseo           #+#    #+#             */
/*   Updated: 2024/05/08 21:25:08 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sort(t_arr *args, t_stack *stack_a)
{
	int	quaternary_flag;

	stack_a->max_digits = get_max_digits(stack_a);
	quaternary_flag = is_quaternary_needed(stack_a->size, stack_a->max_digits);
	if (-1 == add_ternary_value(stack_a))
		return (-1);
	if (0 == quaternary_flag)
		ternary_radix_sort(stack_a, 0);
	else
		ternary_quaternary_radix_sort(stack_a, 0);
	modify_args(args, stack_a);
	update_stack_with_modified_args(args, stack_a);
	update_ternary_value(stack_a);
	if (0 == quaternary_flag)
		ternary_radix_sort(stack_a, 1);
	else
		ternary_quaternary_radix_sort(stack_a, 1);
	return (0);
}

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

void	ternary_quaternary_radix_sort(t_stack *stack_a, int print)
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
