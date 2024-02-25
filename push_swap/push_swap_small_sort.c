/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:29 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/25 22:03:56 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack_a)
{
	t_stack stack_b;

	stack_b = (t_stack){};
	while (3 < stack_a->size)
		pb(stack_a, &stack_b, 1);
	sort_three_partial(stack_a);
	merge_in_stack_a(stack_a, &stack_b);
	stand_stack_up(stack_a);
}

void	sort_three_partial(t_stack *stack_a)
{
	if (!is_stack_partially_sorted(stack_a))
		sa(stack_a, 1);
}

int	is_stack_partially_sorted(t_stack *stack_a)
{
	t_node	*curr;
	size_t	descending_cnt;

	curr = stack_a->top;
	while (curr)
	{
		if (NULL != curr->upper && curr->upper->value > curr->value)
			descending_cnt++;
		curr = curr->lower;
	}
	if (stack_a->bottom->value > stack_a->top->value)
		descending_cnt++;
	if (1 == descending_cnt)
		return (1);
	return (0);
}

void	merge_in_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	instructions;

	while (NULL != stack_b->top)
	{
		instructions = inst_for_fitting_into_a(stack_a, stack_b->top->value);
		merge_top_of_b_into_a(stack_a, stack_b, instructions);
	}
	return (0);
}

int	inst_for_fitting_into_a(t_stack *stack_a, int n)
{
	t_node	*curr;
	int		inst;

	inst = 0;
	curr = stack_a->top;
	while (curr)
	{
		if (curr == stack_a->top)
		{
			if ((stack_a->bottom->value < n && n < curr->value)\
		 || (stack_a->bottom->value > n && n > curr->value))
		 	break;
		}
		else if ((curr->upper->value < n && n < curr->value)\
		 || (curr->upper->value > n && n > curr->value))
			break;
		inst++;
		curr = curr->lower;
	}
	if (n > stack_a->size / 2)
		inst = n - stack_a->size;
	return (inst);
}

void	merge_top_of_b_into_a(t_stack *stack_a, t_stack *stack_b, int inst)
{
	int	i;

	pa(stack_a, stack_b, 1);
	i = 0;
	if (inst >= 0)
		while(i < inst)
		{
			ra(stack_a, 1);
			i++;
		}
	else
		while(i > inst)
		{
			rra(stack_a, 1);
			i--;
		}
}

void	stand_stack_up(t_stack *stack_a)
{

}
