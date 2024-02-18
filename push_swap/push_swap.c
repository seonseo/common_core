/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/18 22:53:04 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (1 == argc)
		return (0);
	stack_a = (t_stack){};
	if (-1 == parse_input(argc, argv, &stack_a))
		return (print_error());
	ternary_radix_sort(&stack_a);
	// ft_print_stack(&stack_a);
	return (0);
}

int	parse_input(int argc, char **argv, t_stack *stack_a)
{
	char **strings;
	int	*arg_arr;
	int	arr_size;
	int	err_flag;

	if (argc == 2)
		strings = ft_split(argv[1], ' ');
	else
		strings = argv + 1;
	arr_size = ft_strslen(strings);
	arg_arr = (int *)malloc(sizeof(*arg_arr) * arr_size);
		if (NULL == arg_arr)
			return (-1);
	err_flag = fill_arr(arr_size, strings, arg_arr);
	if (-1 != err_flag)
		err_flag = check_dup_arr(arg_arr, arr_size);
	if (-1 != err_flag)
		err_flag = rank_based_indexing(&arg_arr, arr_size);
	if (-1 != err_flag)
		err_flag = init_stack_with_index(stack_a, arg_arr, arr_size);
	if (-1 != err_flag)
		err_flag = add_ternary_info_to_stack(stack_a);
	free(arg_arr);
	arg_arr = NULL;
	return (err_flag);
}

void	ternary_radix_sort(t_stack *stack_a)
{
	t_stack	stack_b;
	int		digit_idx;
	int		max_digits;

	stack_b = (t_stack){};
	max_digits = stack_a->max_digits;
	digit_idx = 0;
	while (digit_idx + 1 < max_digits)
	{
		digit_sort_from_a(stack_a, &stack_b, digit_idx);
		digit_idx++;
		reassemble_in_stack_b(stack_a, &stack_b);
		digit_sort_from_b(stack_a, &stack_b, digit_idx);
		digit_idx++;
		reassemble_in_stack_a(stack_a, &stack_b);
	}
	while (digit_idx < max_digits)
	{
		digit_sort_from_a(stack_a, &stack_b, digit_idx);
		digit_idx++;
		reassemble_in_stack_a(stack_a, &stack_b);
	}
} 

int	print_error(void)
{
	ft_printf("Error\n");
	return (-1);
}

size_t	ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

void	ft_print_stack(t_stack *stack)
{
	t_node	*curr;

	curr = stack->top;
	while (NULL != curr)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->lower;
	}
}

void	ft_print_stack_r(t_stack *stack)
{
	ft_print_stack_recur(stack, stack->bottom);
	ft_printf("\n");
}

void	ft_print_stack_recur(t_stack *stack, t_node *curr)
{
	int	i;

	if (NULL == curr)
		return ;
	ft_print_stack_recur(stack, curr->upper);
	i = 0;
	while (i < stack->max_digits)
	{
		ft_printf("%d", (curr->ternary_value)[i]);
		i++;
	}
}
