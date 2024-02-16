/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:42:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/16 19:49:49 by seonseo          ###   ########.fr       */
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
	struct s_node	*upper;
	struct s_node	*lower;
	int				value;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	size_t	size;
}	t_stack;

int		parse_input(int argc, char **argv, t_stack *stack_a);
void	radix_sort(t_stack *stack_a);
int		print_error(void);

int		fill_arr(int argc, char **argv, int *arg_arr);
int		check_dup_arr(int *arr, int size);
int		rank_based_indexing(int **arr, int size);
int		init_stack(t_stack *stack_a, int *arg_arr, int arr_size);

int		ft_atoi_safe(const char *str, int *err_flag);
int		stack_add_bottom(t_stack *stack_a, int n);
void	free_stack(t_stack *stack_a);
t_node	*make_node(int n);

int		get_max_digits(t_stack *stack_a);
void	digit_by_digit_sort(t_stack *stack_a, t_stack *stack_b, int digit_idx);
void	reassemble_in_stack_a(t_stack *stack_a, t_stack *stack_b);
int		get_digit(int value, int digit_idx);

void	ft_swap(t_stack *stack);
void	ft_push(t_stack *stack_from, t_stack *stack_to);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

int		sa(t_stack *stack_a);
int		sb(t_stack *stack_a);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);

int		ra(t_stack *stack_a);
int		rb(t_stack *stack_a);
int		rr(t_stack *stack_a, t_stack *stack_b);

int		rra(t_stack *stack_a);
int		rrb(t_stack *stack_a);
int		rrr(t_stack *stack_a, t_stack *stack_b);

void	ft_print_stack(t_stack *stack_a);
void	ft_print_stack_r(t_stack *stack);
void	ft_print_stack_recur(t_stack *stack, t_node *curr);

#endif
