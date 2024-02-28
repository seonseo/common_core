/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:07:07 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/28 13:21:43 by seonseo          ###   ########.fr       */
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
	else if (is_stack_sorted(&stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_args(&args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (-1 == err_flag)
		return (-1);
	return (0);
}

int	read_and_execute_inst(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		err_flag;

	err_flag = 0;
	while (1)
	{
		line = get_next_line(0);
		if (NULL == line)
			break ;
		err_flag = compare_and_execute_inst(line, stack_a, stack_b);
		free(line);
		if (-1 == err_flag)
			break ;
	}
	if (-1 == err_flag)
		return (-1);
	return (0);
}

int	compare_and_execute_inst(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (0 == ft_strncmp(line, "sa", 2))
		sa(stack_a, 0);
	else if (0 == ft_strncmp(line, "sb\n", 3))
		sb(stack_b, 0);
	else if (0 == ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (0 == ft_strncmp(line, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (0 == ft_strncmp(line, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (0 == ft_strncmp(line, "ra\n", 3))
		ra(stack_a, 0);
	else if (0 == ft_strncmp(line, "rb\n", 3))
		rb(stack_b, 0);
	else if (0 == ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (0 == ft_strncmp(line, "rra\n", 4))
		rra(stack_a, 0);
	else if (0 == ft_strncmp(line, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (0 == ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else
		return (-1);
	return (0);
}
