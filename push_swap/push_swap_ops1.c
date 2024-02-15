/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:08:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/15 19:14:07 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	ft_swap(stack_a);
}
void	sb(t_stack *stack_b)
{
	ft_swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
}
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
}

