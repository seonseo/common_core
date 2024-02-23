/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:59:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/21 21:58:16 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reassemble_in_stack_a(t_stack *stack_a, t_stack *stack_b, int print)
{
	while (NULL != stack_b->top)
		pa(stack_a, stack_b, print);
}

void	reassemble_in_stack_a_last(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	last_digit;

	while (NULL != stack_b->top)
	{
		last_digit = stack_b->top->ternary_value[stack_a->max_digits - 1];
		if (0 == last_digit)
			pa(stack_a, stack_b, print);
		if (1 == last_digit)
		{
			pa(stack_a, stack_b, print);
			if (1 < stack_a->size)
				ra(stack_a, print);
		}
	}
}

void	reassemble_in_stack_b(t_stack *stack_a, t_stack *stack_b, int print)
{
	while (NULL != stack_a->top)
		pb(stack_a, stack_b, print);
}
