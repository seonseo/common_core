/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:29 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 16:03:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_circularly(t_stack *stack_a)
{
	if (!is_stack_circularly_sorted(stack_a))
		sa(stack_a, 1);
}

void	merge_into_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	instructions;

	while (NULL != stack_b->top)
	{
		instructions = inst_for_fitting_into_a(stack_a, stack_b->top->value);
		rotate_a_by_inst(stack_a, instructions);
		pa(stack_a, stack_b, 1);
	}
}

void	stand_stack_up(t_stack *stack_a)
{
	ssize_t	inst;

	inst = inst_for_stading_stack_up(stack_a, 0);
	rotate_a_by_inst(stack_a, inst);
}
