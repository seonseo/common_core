/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/15 19:39:44 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
char	**instructions;	

	if (1 == argc)
		return (0);
	stack_a = (t_stack){};
	if (-1 == parse_input(argc, argv, &stack_a))
		return (print_error());
	radix_sort(&stack_a, instructions);
	print_strs(instructions);
	return (0);
}

int	parse_input(int argc, char **argv, t_stack *stack_a)
{
	int	*arg_arr;
	int	arr_size;
	int	err_flag;

	arg_arr = (int *)malloc(sizeof(*arg_arr) * (argc - 1));
	if (NULL == arg_arr)
		return (-1);
	arr_size = argc - 1;
	err_flag = fill_arr(argc, argv, arg_arr);
	if (-1 != err_flag)
		err_flag = check_dup_arr(arg_arr, arr_size);
	if (-1 != err_flag)
		err_flag = init_stack(stack_a, arg_arr, arr_size);
	return (err_flag);
}

void	radix_sort(t_stack *stack_a, char **instructions)
{
	t_stack	stack_b;


}

void	print_strs(char **strs)
{
	int	i;

	i = 0;
	while (NULL != strs[i])
	{
		ft_printf("%s\n", strs[i]);
		i++;
	}
}

int	print_error(void)
{
	ft_printf("Error\n");
	return (-1);
}
