/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 22:22:26 by seonseo          ###   ########.fr       */
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
	if (-1 != err_flag && !is_stack_sorted(&stack_a))
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
