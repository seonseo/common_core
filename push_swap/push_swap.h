/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:42:02 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/15 22:18:29 by seonseo          ###   ########.fr       */
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
int		init_stack(t_stack *stack_a, int *arg_arr, int arr_size);

int		ft_atoi_safe(const char *str, int *err_flag);
int		stack_add_top(t_stack *stack_a, int n);
void	free_stack(t_stack *stack_a);
t_node	*make_node(int n);

void	ft_swap(t_stack *stack);
void	ft_push(t_stack *stack_from, t_stack *stack_to);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_a);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	ra(t_stack *stack_a);
void	rb(t_stack *stack_a);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_a);
void	rrr(t_stack *stack_a, t_stack *stack_b);



#endif
