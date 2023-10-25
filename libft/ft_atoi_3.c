/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:18:05 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/22 19:52:10 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str[] = "   -02034234";

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}
*/