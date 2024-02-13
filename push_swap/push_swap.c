/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:41:59 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/13 22:28:42 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	char	**solution;

	if (argc == 1)
		return (0);
	stack_a = (t_stack){};
	if (parse_input(argc, argv, &stack_a) == -1)
		return (print_error());
	sort_stack(&stack_a, solution);
	print_solution(solution);
	return (0);
}

int	parse_input(int argc, char **argv, t_stack *stack_a)
{
	int	*arg_arr;
	int	arr_size;

	arg_arr = (int *)malloc(sizeof(int) * (argc - 1));
	arr_size = argc - 1;
	if (fill_arr(argc, argv, arg_arr) == -1)
		return (-1);
	if (check_dup_arr(arg_arr, arr_size) == -1)
		return (-1);
	init_stack(stack_a, arg_arr, arr_size);
	return (0);
}

int	fill_arr(int argc, char **argv, int *arg_arr)
{
	int	i;
	int	err_flag;

	i = 1;
	while (i < argc)
	{
		arg_arr[i - 1] = ft_atoi_safe(argv[i], &err_flag);
		if (err_flag == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi_safe(const char *str, int *err_flag)
{
	size_t		i;
	int			sign;
	long long	number;

	err_flag = 0;
	number = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i++] == '+' || str[i] == '-')
		if (str[i - 1] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		if (number < (-INT_MAX - 1) || INT_MAX < number)
			*err_flag = -1;
		i++;
	}
	if (str[i] != '\0')
		*err_flag = -1;
	return ((int)(number * sign));
}

int	check_dup_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_stack(t_stack *stack_a, int *arg_arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (stack_add_top(stack_a, arg_arr[i]) == -1)
		{
			free_stack(stack_a);
			return (-1);
		}
		i++;
	}
}

int	add_node(t_stack *stack_a, int n)
{
	
}

int	print_error(void)
{
	printf("Error\n");
	return (1);
}
