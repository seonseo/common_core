/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:18:05 by seonseo           #+#    #+#             */
/*   Updated: 2024/04/30 23:00:37 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skip_whitespace(const char *str)
{
	while (ft_isspace((int)*str))
		str++;
	return (str);
}

static const char	*handle_sign(const char	*str, int *sign)
{
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		else
			*sign = 1;
		str++;
	}
	return (str);
}

static const char	*determine_base(const char *str, int *base)
{
	if (*base == 0)
	{
		if (*str == '0')
		{
			str++;
			if (*str == 'x' || *str == 'X')
			{
				str++;
				*base = 16;
			}
			else
				*base = 8;
		}
		else
			*base = 10;
	}
	else if (*base == 16)
	{
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
			str += 2;
	}
	return (str);
}

static int	char_to_digit(char c, int base)
{
	int	digit;

	if (ft_isdigit(c))
		digit = c - '0';
	else if (ft_isalpha(c))
		digit = ft_toupper(c) - 'A' + 10;
	else
		digit = -1;
	if (digit >= base)
		digit = -1;
	return (digit);
}

int	check_overflow(long result, int base, int sign, int digit)
{
	if (sign == 1)
	{
		if ((result > LONG_MAX / base) || \
			((result == LONG_MAX / base) && (digit > LONG_MAX % base)))
			return (1);
	}
	else
	{
		if ((result > LONG_MAX / base) || \
			((result == LONG_MAX / base) && (digit > LONG_MAX % base + 1)))
			return (1);
	}
	return (0);
}

static long	convert_to_number(const char *str, int base, int sign, char **endptr)
{
    long	result;
	int		digit;

	result = 0;
	while (*str)
	{
		digit = char_to_digit(*str, base);
		if (digit == -1)
			break;
		if (check_overflow(result, base, sign, digit))
		{
			errno = ERANGE;
			break;
		}
		if ()

		result = result * base + digit;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}

long ft_strtol(const char *str, char **endptr, int base)
{
    int sign;

	sign = 1;
    str = skip_whitespace(str);
    str = handle_sign(str, &sign);
    str = determine_base(str, &base);
    return (convert_to_number(str, base, sign, endptr));
}

		if (sign == 1)
		{
			if ((result > LONG_MAX / base) || \
				((result == LONG_MAX / base) && (digit > LONG_MAX % base)))
			{
				errno = ERANGE;
				result = LONG_MAX;
				break;
			}
		}
		else
		{
			if ((result > LONG_MAX / base) || \
				((result == LONG_MAX / base) && (digit > LONG_MAX % base + 1)))
			{
				errno = ERANGE;
				result = -LONG_MAX - 1L;
				break;
			}
			else if ((result > LONG_MAX / base) || \
				((result == LONG_MAX / base) && (digit > LONG_MAX % base)))
				result = -LONG_MAX - 1L;
		}
