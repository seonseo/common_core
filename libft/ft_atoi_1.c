/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:18:05 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/24 19:08:55 by seonseo          ###   ########.fr       */
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
	int		i;
	int		sign;
	long	number;

	number = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (number == 922337203685477580 && '8' <= str[i] && str[i] <= '9')
		{
			if (sign == -1)
				return ((int)(LONG_MIN));
			else
				return ((int)(LONG_MAX));
		}
		if (9223372036854775800 <= number && number <= 9223372036854775807 && ft_isdigit(str[i]))
		{
			if (sign == -1)
				return ((int)(LONG_MIN));
			else
				return ((int)(LONG_MAX));
		}
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str[] = "-92233720368547758089";

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}
