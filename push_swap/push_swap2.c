/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/29 19:54:59 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack_a)
{
	if (0 == stack_a->size)
		return (1);
	if (is_stack_circularly_sorted(stack_a) && 0 == stack_a->top->value)
		return (1);
	return (0);
}

int	is_stack_circularly_sorted(t_stack *stack_a)
{
	t_node	*curr;
	ssize_t	descending_cnt;

	if (1 == stack_a->size)
		return (1);
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

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

void	free_args(t_arr *args)
{
	free(args->arr);
	*args = (t_arr){};
}

void	free_stack(t_stack *stack_a)
{
	t_node	*curr;
	t_node	*prev;

	prev = NULL;
	curr = stack_a->top;
	while (curr)
	{
		prev = curr;
		curr = curr->lower;
		free(prev->ternary_value);
		*prev = (t_node){};
		free(prev);
	}
	prev = NULL;
	*stack_a = (t_stack){};
}
