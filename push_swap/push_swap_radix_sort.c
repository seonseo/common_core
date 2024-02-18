/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:59:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/18 22:52:51 by seonseo          ###   ########.fr       */
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

void	digit_sort_from_a(t_stack *stack_a, t_stack *stack_b, int digit_idx)
{
	int		digit;
	int		repeat;
	int		i;

	repeat = stack_a->size;
	i = 0;
	while (i < repeat)
	{
		digit = (stack_a->top->ternary_value)[digit_idx];
		if (0 == digit)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if (1 == digit)
			pb(stack_a, stack_b);
		else if (2 == digit)
			ra(stack_a);
		i++;
	}
}

void	digit_sort_from_b(t_stack *stack_a, t_stack *stack_b, int digit_idx)
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
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (1 == digit)
			pa(stack_a, stack_b);
		else if (0 == digit)
			rb(stack_b);
		i++;
	}
}

void	reassemble_in_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	while (NULL != stack_b->top)
		pa(stack_a, stack_b);
}

void	reassemble_in_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	while (NULL != stack_a->top)
		pb(stack_a, stack_b);
}
