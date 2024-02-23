/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:59:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/21 22:22:33 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_sort_from_a(t_stack *stack_a, t_stack *stack_b, int digit_idx, int print)
{
	int		digit;
	int		repeat;
	int		i;

	repeat = stack_a->size;
	i = 0;
	while (i < repeat)
	{
		digit = (stack_a->top->ternary_value)[digit_idx];
		if (1 == digit)
		{
			pb(stack_a, stack_b, print);
			if (1 < stack_b->size)
				rb(stack_b, print);
		}
		else if (0 == digit)
			pb(stack_a, stack_b, print);
		else if (2 == digit)
			if (1 < stack_a->size)
				ra(stack_a, print);
		i++;
	}
}

void	digit_sort_from_b(t_stack *stack_a, t_stack *stack_b, int digit_idx, int print)
{
	int		digit;
	int		repeat;
	int		i;

	repeat = stack_b->size;
	i = 0;
	while (i < repeat)
	{
		digit = (stack_b->top->ternary_value)[digit_idx];
		if (1 == digit)
		{
			pa(stack_a, stack_b, print);
			if (1 < stack_a->size)
				ra(stack_a, print);
		}
		else if (0 == digit)
			pa(stack_a, stack_b, print);
		else if (2 == digit)
			if (1 < stack_b->size)
				rb(stack_b, print);
		i++;
	}
}

void	digit_sort_from_b_last(t_stack *stack_a, t_stack *stack_b, int digit_idx, int print)
{
	int		digit;
	int		repeat;
	int		i;

	repeat = stack_b->size;
	i = 0;
	while (i < repeat)
	{
		digit = (stack_b->top->ternary_value)[digit_idx];
		if (2 == digit)
		{
			pa(stack_a, stack_b, print);
			if (1 < stack_a->size)
				ra(stack_a, print);
		}
		else if (1 == digit)
			pa(stack_a, stack_b, print);
		else if (0 == digit)
			if (1 < stack_b->size)
				rb(stack_b, print);
		i++;
	}
}
