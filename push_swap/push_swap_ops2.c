/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:08:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/19 17:49:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack_a, int print)
{
	ft_rotate(stack_a);
	if (1 == print)
		if (-1 == write(1, "ra\n", 3))
			return (-1);
	return (0);
}

int	rb(t_stack *stack_b, int print)
{
	ft_rotate(stack_b);
	if (1 == print)
		if (-1 == write(1, "rb\n", 3))
			return (-1);
	return (0);
}

int	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (1 == print)
		if (-1 == write(1, "rr\n", 3))
			return (-1);
	return (0);
}
