/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/19 21:11:31 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_arr	args;
	int		err_flag;

	if (1 == argc)
		return (0);
	stack_a = (t_stack){};
	err_flag = parse_input(argc, argv, &args);
	if (-1 != err_flag)
		err_flag = init_stack_with_arguments(&args, &stack_a);
	if (-1 != err_flag)
		err_flag = radix_sort(&args, &stack_a);
	free_stack(&stack_a);
	if (-1 == err_flag)
		return (print_error());
	return (0);
}

int	parse_input(int argc, char **argv, t_arr *args)
{
	char **strings;
	int	err_flag;

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
	return (err_flag);
}

int	radix_sort(t_arr *args, t_stack *stack_a)
{
	if (-1 == ternary_radix_sort(stack_a, 0))
		return (-1);
	modify_arguments(args, stack_a);
	free_stack(stack_a);
	if (-1 == init_stack_with_arguments(args, stack_a))
		return (-1);
	if (-1 == ternary_radix_sort(stack_a, 1))
		return (-1);
	return (0);
}

int	init_stack_with_arguments(t_arr *args, t_stack *stack_a)
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

size_t	ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
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
