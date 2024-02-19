/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:08:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/19 17:49:04 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack_a, int print)
{
	ft_swap(stack_a);
	if (1 == print)
		if (-1 == write(1, "sa\n", 3))
			return (-1);
	return (0);
}

int	sb(t_stack *stack_b, int print)
{
	ft_swap(stack_b);
	if (1 == print)
		if (-1 == write(1, "sb\n", 3))
			return (-1);
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (1 == print)
		if (-1 == write(1, "ss\n", 3))
			return (-1);
	return (0);
}

int	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_push(stack_b, stack_a);
	if (1 == print)
		if (-1 == write(1, "pa\n", 3))
			return (-1);
	return (0);
}

int	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_push(stack_a, stack_b);
	if (1 == print)
		if (-1 == write(1, "pb\n", 3))
			return (-1);
	return (0);
}
