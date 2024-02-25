/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sort1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:29 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 01:41:27 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_circularly_sorted(t_stack *stack_a)
{
	t_node	*curr;
	ssize_t	descending_cnt;

	descending_cnt = 0;
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

ssize_t	inst_for_fitting_into_a(t_stack *stack_a, int n)
{
	t_node	*curr;
	ssize_t	inst;

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
	if (inst > (ssize_t)(stack_a->size / 2))
		inst = inst - stack_a->size;
	return (inst);
}

void	rotate_a_as_inst(t_stack *stack_a, ssize_t inst)
{
	ssize_t	i;

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

ssize_t	how_many_times_to_rotate(t_stack *stack, int n)
{
	ssize_t	i;
	t_node	*curr;

	i = 0;
	curr = stack->top;
	while (NULL != curr)
	{
		if (curr->value == n)
			break;
		i++;
		curr = curr->lower;
	}
	if (i > (ssize_t)(stack->size / 2))
		i = i - stack->size;
	return (i);
}
