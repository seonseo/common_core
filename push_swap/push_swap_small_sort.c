/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:29 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/02 15:06:05 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack_a)
{
	t_stack	stack_b;

	stack_b = (t_stack){};
	while (3 < stack_a->size)
		pb(stack_a, &stack_b, 1);
	sort_three_circularly(stack_a);
	merge_into_stack_a(stack_a, &stack_b);
	stand_stack_up(stack_a);
}

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
