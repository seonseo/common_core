/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:59:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/16 19:43:57 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_digits(t_stack *stack_a)
{
	int		max_digits;
	int		max_value;

	max_value = (stack_a->size) - 1;
	max_digits = 0;
	while (1)
	{
		max_value /= 3;
		max_digits++;
		if (0 == max_value)
			break;
	}
	return (max_digits);
}

void	digit_by_digit_sort(t_stack *stack_a, t_stack *stack_b, int digit_idx)
{
	int		digit;
	int		repeat;
	int		i;

	repeat = (stack_a->size);
	i = 0;
	while (i < repeat)
	{
		digit = get_digit(stack_a->top->value, digit_idx);
		ft_printf("---\n");
		ft_print_stack(stack_a);
		ft_print_stack(stack_b);
		ft_print_stack_r(stack_a);
		ft_print_stack_r(stack_b);
		ft_printf("digit:%d\n", digit);
		if (0 == digit)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if (1 == digit)
			pb(stack_a, stack_b);
		else if (2 == digit)
			ra(stack_a);
		i++;
	}
}

int	get_digit(int value, int digit_idx)
{
	int	i;

	i = 0;
	while (i < digit_idx - 1)
	{
		value /= 3;
		i++;
	}
	return (value % 3);
}

void	reassemble_in_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("---\n");
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	ft_print_stack_r(stack_a);
	ft_print_stack_r(stack_b);
	ft_printf("reassamble\n");
	while (NULL != stack_b->top)
		pa(stack_a, stack_b);
}
