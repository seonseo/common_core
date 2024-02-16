/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:08:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/16 11:31:44 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *stack_a)
{
	ft_reverse_rotate(stack_a);
	if (-1 == write(1, "rra\n", 4))
		return (-1);
	return (0);
}

int	rrb(t_stack *stack_b)
{
	ft_reverse_rotate(stack_b);
	if (-1 == write(1, "rrb\n", 4))
		return (-1);
	return (0);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (-1 == write(1, "rrr\n", 4))
		return (-1);
	return (0);
}
