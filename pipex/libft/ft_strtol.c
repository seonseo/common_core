/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:18:05 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/29 23:22:12 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	ft_strtol_isdigit(char c, int base)
{
	int	n;

	n = ft_tolower(c);
	
}

int	ft_ctoi(const char *c)
{
	int	n;

	n = ft_tolower(c);

	if ('0' <= n && n <= '9')
		return (n - '0');
	else if ('a' <= n && n <= 'z')
		return (n - 'a' + 10);
	else
		return (0);
}

long	ft_strtol(const char *restrict str, char **restrict endptr, int base)
{
	size_t	i;
	int		digit;
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
	while (ft_strtol_isdigit(str[i], base))
	{
		digit = ft_ctoi(str[i]);
		if ((number > LONG_MAX / base) || \
		((number == LONG_MAX / base) && (digit > LONG_MAX % base)))
		{
			if (sign == 1)
			{
				errno = ERANGE;
				number = LONG_MAX;
				break;
			}
			else
			{
				if (digit > LONG_MAX % base + 1 || \
				ft_strtol_isdigit(str[i + 1], base))
					errno = ERANGE;
				number = -LONG_MAX -1L;
				sign = 1;
				break;
			}
		}
		number = number * base + digit;
		i++;
	}
	while (ft_strtol_isdigit(str[i], base))
		i++;
	if (str[i] != '\0' && endptr != NULL)
		*endptr = &str[i];
	return (number * sign);
}
