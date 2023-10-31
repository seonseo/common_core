/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:18:05 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/31 13:56:20 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || (c == 32))
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	size_t	i;
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
		if (number > LONG_MAX / 10 || (number == LONG_MAX / 10 && str[i] > (char)(LONG_MAX % 10)))
			return (-(sign == 1));
		number = number * 10 + str[i] - '0';
		i++;
	}
	return ((int)(number * sign));
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "9223372036854775807";

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}