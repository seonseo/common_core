/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 16:24:36 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");
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
