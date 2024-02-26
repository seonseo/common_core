/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix_sort4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:59:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/02/26 16:53:55 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_quaternary_needed(size_t size, int max_digits)
{
	if (is_in_scope(size) && (1 == max_digits % 2))
		return (1);
	return (0);
}

int	is_in_scope(int n)
{
	int	k;
	int	lowerbound;
	int	upperbound;

	lowerbound = 0;
	k = 1;
	while (lowerbound <= n)
	{
		lowerbound = ft_pow(3, k) + 1;
		upperbound = lowerbound + ft_pow(3, k - 1) - 1;
		if (lowerbound <= n && n <= upperbound)
			return (1);
		k++;
	}
	return (0);
}

int	ft_pow(int base, int exponent)
{
	int	number;
	int	i;

	number = 1;
	i = 0;
	while (i < exponent)
	{
		number *= base;
		i++;
	}
	return (number);
}
