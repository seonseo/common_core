/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:42:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 01:00:20 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "printf/ft_printf.h"
# include "printf/libft/libft.h"

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

typedef struct	s_arr
{
	int		*arr;
	size_t	size;
}	t_arr;

//push.swap.c
int		parse_input(int argc, char **argv, t_arr *args, t_stack *stack_a);
int		init_stack_with_args(t_arr *args, t_stack *stack_a);
int		radix_sort(t_arr *args, t_stack *stack_a);
int		print_error(void);
void	free_args(t_arr *args);
//push_swap_parse_input.c
int		fill_arr(t_arr *args, char **strings);
int		check_dup_arr(t_arr *args);
int		rank_based_indexing(t_arr *args);
size_t	ft_strslen(char **strs);
//push_swap_parse_input1.c
int		ft_atoi_safe(const char *str, int *err_flag);
int		stack_add_bottom(t_stack *stack_a, int n);
void	free_stack(t_stack *stack_a);
t_node	*make_node(int n);
//push_swap_radix_sort.c
void	ternary_radix_sort(t_stack *stack_a, int print);
void	ternary_radix_sort_1(t_stack *stack_a, int print);
void	modify_args(t_arr *args, t_stack *stack_a);
int		get_nth_value(t_stack *stack, size_t n);
void	update_stack_with_modified_args(t_arr *args, t_stack *stack_a);
//push_swap_radix_sort1.c
int		get_max_digits(t_stack *stack_a);
int		add_ternary_value(t_stack *stack_a);
void	update_ternary_value(t_stack *stack_a);
int		malloc_ternary_value(t_node *curr, int max_digits);
void	decimal_to_ternary(t_node *curr, int max_digits);
//push_swap_radix_sort2.c
void	digit_sort_from_a(t_stack *stack_a, t_stack *stack_b, int digit_idx, int print);
void	digit_sort_from_b(t_stack *stack_a, t_stack *stack_b, int digit_idx, int print);
void	digit_sort_from_b_last(t_stack *stack_a, t_stack *stack_b, int digit_idx, int print);
//push_swap_radix_sort3.c
void	reassemble_in_stack_a(t_stack *stack_a, t_stack *stack_b, int print);
void	reassemble_in_stack_b(t_stack *stack_a, t_stack *stack_b, int print);
void	reassemble_in_stack_a_last(t_stack *stack_a, t_stack *stack_b, int print);
//push_swap_radix_sort4.c
int		is_quaternary_needed(size_t size, int max_digits);
int		is_in_scope(int n);
int		ft_pow(int base, int exponent);
//push_swap_small_sort.c
void	small_sort(t_stack *stack_a);
void	sort_three_circularly(t_stack *stack_a);
void	merge_into_stack_a(t_stack *stack_a, t_stack *stack_b);
void	stand_stack_up(t_stack *stack_a);
//push_swap_small_sort1.c
int		is_stack_circularly_sorted(t_stack *stack_a);
ssize_t	inst_for_fitting_into_a(t_stack *stack_a, int n);
void	rotate_a_as_inst(t_stack *stack_a, ssize_t inst);
ssize_t	how_many_times_to_rotate(t_stack *stack, int n);
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
// debugging functions ./push.swap.c
void	print_stack(t_stack *stack_a);
void	print_stack_ternary(t_stack *stack);

#endif
