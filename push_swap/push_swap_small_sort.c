/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:29 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/23 15:46:59 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack_a)
{
	t_stack stack_b;

	stack_b = (t_stack){};
	while (3 < stack_a->size)
		pb(stack_a, &stack_b, 1);
	sort_three(stack_a);
	merge_in_stack_a(stack_a, &stack_b);
	stand_stack_up(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top->value;
	second = stack_a->top->lower->value;
	third = stack_a->bottom->value;
	if (0)
}

void	merge_in_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int		
}

int	is_stack_partially_sorted(t_stack *stack_a)
{
	t_node	*curr;
	t_node	*prev;

	prev = NULL;
	curr = stack_a->top;
	while (curr)
	{
		if (NULL != prev && prev->value + 1 != curr->value && 0 != curr->value)
			return (0);
		prev = curr;
		curr = curr->next;
	}
}
