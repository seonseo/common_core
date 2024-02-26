/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 22:18:09 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_arr *args, t_stack *stack_a)
{
	char	**strings;
	int		err_flag;

	err_flag = get_strs(argc, argv, &strings);
	if (-1 != err_flag)
		err_flag = get_args(args, strings);
	if (-1 != err_flag)
		err_flag = fill_arr(args, strings);
	if (-1 != err_flag)
		err_flag = check_dup_arr(args);
	if (-1 != err_flag)
		err_flag = rank_based_indexing(args);
	if (-1 != err_flag)
		err_flag = init_stack_with_args(args, stack_a);
	if (2 == argc)
		free_strs(&strings);
	return (err_flag);
}

void	small_sort(t_stack *stack_a)
{
	t_stack	stack_b;

	stack_b = (t_stack){};
	while (3 < stack_a->size)
		pb(stack_a, &stack_b, 1);
	sort_three_circularly(stack_a);
	merge_into_stack_a(stack_a, &stack_b);
	stand_stack_up(stack_a);
}

int	radix_sort(t_arr *args, t_stack *stack_a)
{
	int	quaternary_flag;

	stack_a->max_digits = get_max_digits(stack_a);
	quaternary_flag = is_quaternary_needed(stack_a->size, stack_a->max_digits);
	if (-1 == add_ternary_value(stack_a))
		return (-1);
	if (0 == quaternary_flag)
		ternary_radix_sort(stack_a, 0);
	else
		ternary_radix_sort_1(stack_a, 0);
	modify_args(args, stack_a);
	update_stack_with_modified_args(args, stack_a);
	update_ternary_value(stack_a);
	if (0 == quaternary_flag)
		ternary_radix_sort(stack_a, 1);
	else
		ternary_radix_sort_1(stack_a, 1);
	return (0);
}

int	is_stack_sorted(t_stack *stack_a)
{
	if (is_stack_circularly_sorted(stack_a) && 0 == stack_a->top->value)
		return (1);
	return (0);
}

// void	print_stack(t_stack *stack)
// {
// 	t_node	*curr;

// 	curr = stack->top;
// 	while (NULL != curr)
// 	{
// 		ft_printf("%d\n", curr->value);
// 		curr = curr->lower;
// 	}
// }

// void	print_stack_ternary(t_stack *stack)
// {
// 	t_node	*curr;
// 	int		i;

// 	curr = stack->top;
// 	ft_printf("max_digits:%d\n", stack->max_digits);
// 	while (NULL != curr)
// 	{
// 		i = 0;
// 		while (i < stack->max_digits)
// 		{
// 			ft_printf("%d", (curr->ternary_value)[i]);
// 			i++;
// 		}
// 		ft_printf("\n");
// 		curr = curr->lower;
// 	}
// }
