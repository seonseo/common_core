/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:42:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/28 13:24:04 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				*ternary_value;
	struct s_node	*upper;
	struct s_node	*lower;
}	t_node;

typedef struct s_stack
{
	size_t	size;
	int		max_digits;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_arr
{
	int		*arr;
	size_t	size;
}	t_arr;

//push_swap2.c
int		is_stack_sorted(t_stack *stack_a);
int		is_stack_circularly_sorted(t_stack *stack_a);
int		print_error(void);
void	free_args(t_arr *args);
void	free_stack(t_stack *stack_a);
//push_swap_parse_input.c
int		parse_input(int argc, char **argv, t_arr *args, t_stack *stack_a);
int		get_strs(int argc, char **argv, char ***strings);
int		malloc_args(t_arr *args, char **strings);
void	free_strs(char ***strings);
int		fill_arr(t_arr *args, char **strings);
//push_swap_parse_input1.c
int		check_dup_arr(t_arr *args);
int		rank_based_indexing(t_arr *args);
int		init_stack_with_args(t_arr *args, t_stack *stack_a);
size_t	ft_strslen(char **strs);
//push_swap_parse_input2.c
int		ft_atoi_safe(const char *str, int *err_flag);
int		stack_add_bottom(t_stack *stack_a, int n);
t_node	*make_node(int n);
//push_swap_ops.c
void	ft_swap(t_stack *stack);
void	ft_push(t_stack *stack_from, t_stack *stack_to);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
//push_swap_ops1.c
int		sa(t_stack *stack_a, int print);
int		sb(t_stack *stack_a, int print);
int		ss(t_stack *stack_a, t_stack *stack_b, int print);
int		pa(t_stack *stack_a, t_stack *stack_b, int print);
int		pb(t_stack *stack_a, t_stack *stack_b, int print);
//push_swap_ops2.c
int		ra(t_stack *stack_a, int print);
int		rb(t_stack *stack_a, int print);
int		rr(t_stack *stack_a, t_stack *stack_b, int print);
//push_swap_ops3.c
int		rra(t_stack *stack_a, int print);
int		rrb(t_stack *stack_a, int print);
int		rrr(t_stack *stack_a, t_stack *stack_b, int print);
//checker.c
int		read_and_execute_inst(t_stack *stack_a, t_stack *stack_b);
int		compare_and_execute_inst(char *line, \
t_stack *stack_a, t_stack *stack_b);

#endif
