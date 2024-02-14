/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:08:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/14 21:49:20 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
//swap, push, rotate, reverse_rotate

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
	t_node	*to_second;

	if (NULL == stack_from->top)
		return ;
	from_first = stack_from->top;
	from_second = from_first->lower;
	to_first = stack_to->top;
	to_second = to_first->lower;

	from_first->lower = to_second;
	from_second->upper = to_first;
	to_first->lower = from_second;
	to_second->upper = from_first;
	
	stack_from->top = to_first;
	stack_to->top = from_first;
}

void	ft_rotate(t_stack *stack)
{

}

void	ft_reverse_rotate(t_stack *stack)
{
	
}
