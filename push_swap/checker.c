/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:07:07 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 22:53:03 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_arr	args;
	t_stack	stack_a;
	t_stack	stack_b;
	int		err_flag;

	if (1 == argc)
		return (0);
	stack_a = (t_stack){};
	stack_b = (t_stack){};
	err_flag = parse_input(argc, argv, &args, &stack_a);
	if (-1 != err_flag)
		err_flag = read_and_execute_inst(&stack_a, &stack_b);
	if (-1 == err_flag)
		write(1, "Error\n", 6);
	else
	{
		if (is_stack_sorted(&stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_args(&args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	read_and_execute_inst(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		err_flag;

	while (1)
	{
		line = get_next_line(0);
		if (NULL == line)
			break;
		err_flag = compare_and_execute_inst(line, stack_a, stack_b);
		free(line);
		line = NULL;
		if (-1 == err_flag)
			break;
	}
	if (-1 == err_flag)
		return (-1);
	return (0);
}

int	compare_and_execute_inst(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (0 == ft_strncmp(line, "sa", 2))
		sa(stack_a, 0);
	else if (0 ==  ft_strncmp(line, "sb", 2))
		sb(stack_b, 0);
	else if (0 ==  ft_strncmp(line, "ss", 2))
		ss(stack_a, stack_b, 0);
	else if (0 ==  ft_strncmp(line, "pa", 2))
		pa(stack_a, stack_b, 0);
	else if (0 ==  ft_strncmp(line, "pb", 2))
		pb(stack_a, stack_b, 0);
	else if (0 ==  ft_strncmp(line, "ra", 2))
		ra(stack_a, 0);
	else if (0 ==  ft_strncmp(line, "rb", 2))
		rb(stack_b, 0);
	else if (0 ==  ft_strncmp(line, "rr", 2))
		rr(stack_a, stack_b, 0);
	else if (0 ==  ft_strncmp(line, "rra", 3))
		rra(stack_a, 0);
	else if (0 ==  ft_strncmp(line, "rrb", 3))
		rrb(stack_b, 0);
	else if (0 ==  ft_strncmp(line, "rrr", 3))
		rrr(stack_a, stack_b, 0);
	else
		return (-1);
	return (0);
}
