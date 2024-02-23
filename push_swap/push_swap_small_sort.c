/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:29 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/23 22:56:47 by seonseo          ###   ########.fr       */
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
	int	*cost_a_arr;
	int	*total_cost_arr;
	int	i;

	cost_a_arr = (int *)malloc(sizeof(int) * stack_b->size);
	i = 0;
	while (i < stack_b->size)
	{
		cost_a_arr[i] = cost_of_fitting_into_a(stack_a, get_nth_value(stack_b, i));
		i++;
	}
}

int	cost_of_fitting_into_a(t_stack *stack_a, int n)
{
	t_node	*curr;
	int		cost;

	cost = 0;
	curr = stack_a->top;
	while (curr)
	{
		if (NULL != curr->upper && curr->upper->value <= n && n <= curr->value)
			break;
		cost++;
		curr = curr->next;
	}
	return (cost);
}

int	get_nth_value(t_stack *stack, size_t n)
{

}
