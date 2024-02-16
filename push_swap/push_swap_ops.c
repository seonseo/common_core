/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:08:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/16 19:21:41 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (NULL == stack->top || NULL == stack->top->lower)
		return ;
	first = stack->top;
	second = first->lower;
	third = second->lower;
	first->upper = second;
	first->lower = third;
	second->upper = NULL;
	second->lower = first;
	if (NULL != third)
		third->upper = first;
	stack->top = second;
}

void	ft_push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*from_first;
	t_node	*from_second;
	t_node	*to_first;

	if (NULL == stack_from->top)
		return ;
	from_first = stack_from->top;
	from_second = from_first->lower;
	to_first = stack_to->top;
	from_first->lower = to_first;
	if (NULL != to_first)
		to_first->upper = from_first;
	if (NULL != from_second)
		from_second->upper = NULL;
	stack_to->top = from_first;
	if (NULL == to_first)
		stack_to->bottom = from_first;
	stack_from->top = from_second;
	if (NULL == from_second)
	stack_from->bottom = NULL;
	(stack_from->size)--;
	(stack_to->size)++;
}

void	ft_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (NULL == stack->top || NULL == stack->top->lower)
		return ;
	first = stack->top;
	second = first->lower;
	last = stack->bottom;
	first->upper = last;
	first->lower = NULL;
	second->upper = NULL;
	if (NULL != last)
		last->lower = first;
	stack->top = second;
	stack->bottom = first;
}

void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second_last;
	t_node	*last;

	if (NULL == stack->bottom->upper)
		return ;
	first = stack->top;
	last = stack->bottom;
	second_last = last->upper;
	first->upper = last;
	second_last->lower = NULL;
	last->upper = NULL;
	last->lower = first;
	stack->top = last;
	stack->bottom = second_last;
}
