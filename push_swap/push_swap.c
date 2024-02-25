/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 00:31:12 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arr	args;
	t_stack	stack_a;
	int		err_flag;

	if (1 == argc)
		return (0);
	stack_a = (t_stack){};
	err_flag = parse_input(argc, argv, &args, &stack_a);
	if (-1 != err_flag)
	{
		if (stack_a.size <= 5)
			small_sort(&stack_a);
		else
			err_flag = radix_sort(&args, &stack_a);
	}
	free_stack(&stack_a);
	free_args(&args);
	if (-1 == err_flag)
		return (print_error());
	return (0);
}

int	parse_input(int argc, char **argv, t_arr *args, t_stack *stack_a)
{
	char	**strings;
	int		err_flag;

	if (2 == argc)
		strings = ft_split(argv[1], ' ');
	else
		strings = argv + 1;
	args->size = ft_strslen(strings);
	args->arr = (int *)malloc(sizeof(*(args->arr)) * args->size);
	if (NULL == args->arr)
		return (-1);
	err_flag = fill_arr(args, strings);
	if (-1 != err_flag)
		err_flag = check_dup_arr(args);
	if (-1 != err_flag)
		err_flag = rank_based_indexing(args);
	if (-1 != err_flag)
		err_flag = init_stack_with_args(args, stack_a);
	return (err_flag);
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

int	init_stack_with_args(t_arr *args, t_stack *stack_a)
{
	size_t	i;

	i = 0;
	while (i < args->size)
	{
		if (-1 == stack_add_bottom(stack_a, (args->arr)[i]))
		{
			free_stack(stack_a);
			return (-1);
		}
		i++;
	}
	stack_a->size = args->size;
	return (0);
}

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

void	print_stack(t_stack *stack)
{
	t_node	*curr;

	curr = stack->top;
	while (NULL != curr)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->lower;
	}
}

void	print_stack_ternary(t_stack *stack)
{
	t_node	*curr;
	int		i;

	curr = stack->top;
	ft_printf("max_digits:%d\n", stack->max_digits);
	while (NULL != curr)
	{
		i = 0;
		while (i < stack->max_digits)
		{
			ft_printf("%d", (curr->ternary_value)[i]);
			i++;
		}
		ft_printf("\n");
		curr = curr->lower;
	}
}
